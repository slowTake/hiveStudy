#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

enum {
	MAX_CLIENTS = 1024,
	BUF_SIZE = 100000,
	READ_CHUNK = 1024
};

typedef struct s_client {
	int		fd;
	int		id;
	char	buf[BUF_SIZE];
}	t_client;

static t_client	g_clients[MAX_CLIENTS];
static int		g_next_id;
static char		g_out[BUF_SIZE];

static void	fatal(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

static void	broadcast(int except_fd, const char *msg, fd_set *wfds)
{
	int	i;

	for (i = 0; i < MAX_CLIENTS; i++)
	{
		if (g_clients[i].fd == -1 || g_clients[i].fd == except_fd)
			continue;
		if (FD_ISSET(g_clients[i].fd, wfds))
			send(g_clients[i].fd, msg, strlen(msg), 0);
	}
}

static void	remove_client(int idx, fd_set *all, fd_set *wfds)
{
	sprintf(g_out, "server: client %d just left\n", g_clients[idx].id);
	broadcast(g_clients[idx].fd, g_out, wfds);
	FD_CLR(g_clients[idx].fd, all);
	close(g_clients[idx].fd);
	g_clients[idx].fd = -1;
	memset(g_clients[idx].buf, 0, BUF_SIZE);
}

static void	accept_client(int sockfd, fd_set *all, int *maxfd, fd_set *wfds)
{
	int				cfd;
	int				i;
	socklen_t		len;
	struct sockaddr_in	caddr;

	len = sizeof(caddr);
	cfd = accept(sockfd, (struct sockaddr *)&caddr, &len);
	if (cfd < 0)
		return;
	for (i = 0; i < MAX_CLIENTS; i++)
	{
		if (g_clients[i].fd != -1)
			continue;
		g_clients[i].fd = cfd;
		g_clients[i].id = g_next_id++;
		memset(g_clients[i].buf, 0, BUF_SIZE);
		FD_SET(cfd, all);
		if (cfd > *maxfd)
			*maxfd = cfd;
		sprintf(g_out, "server: client %d just arrived\n", g_clients[i].id);
		broadcast(cfd, g_out, wfds);
		break;
	}
}

static void	process_line(int idx, int end, fd_set *wfds)
{
	char	line[BUF_SIZE];
	int		j;

	j = 0;
	while (j < end)
	{
		line[j] = g_clients[idx].buf[j];
		j++;
	}
	line[j] = '\0';
	sprintf(g_out, "client %d: %s", g_clients[idx].id, line);
	broadcast(g_clients[idx].fd, g_out, wfds);
}

static void	append_and_dispatch(int idx, const char *chunk, int n, fd_set *wfds)
{
	int		i;
	int		j;
	int		k;
	char	combined[BUF_SIZE];

	j = strlen(g_clients[idx].buf);
	for (i = 0; i < n; i++)
		g_clients[idx].buf[j++] = chunk[i];
	g_clients[idx].buf[j] = '\0';
	i = 0;
	while (g_clients[idx].buf[i])
	{
		k = i;
		while (g_clients[idx].buf[k] && g_clients[idx].buf[k] != '\n')
			k++;
		if (g_clients[idx].buf[k] == '\n')
		{
			process_line(idx, k + 1, wfds);
			strcpy(combined, g_clients[idx].buf + k + 1);
			memset(g_clients[idx].buf, 0, BUF_SIZE);
			strcpy(g_clients[idx].buf, combined);
			i = 0;
		}
		else
			break;
	}
}

static void	handle_client(int idx, fd_set *all, fd_set *wfds)
{
	char	chunk[READ_CHUNK];
	int		n;

	n = recv(g_clients[idx].fd, chunk, READ_CHUNK - 1, 0);
	if (n <= 0)
	{
		remove_client(idx, all, wfds);
		return;
	}
	chunk[n] = '\0';
	append_and_dispatch(idx, chunk, n, wfds);
}

int	main(int argc, char **argv)
{
	int					sockfd;
	int					maxfd;
	int					i;
	int					port;
	fd_set				rfds;
	fd_set				wfds;
	fd_set				all;
	struct sockaddr_in	addr;

	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	port = atoi(argv[1]);
	for (i = 0; i < MAX_CLIENTS; i++)
		g_clients[i].fd = -1;
	g_next_id = 0;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal();
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433);
	addr.sin_port = htons(port);
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		fatal();
	if (listen(sockfd, 128) < 0)
		fatal();
	FD_ZERO(&all);
	FD_SET(sockfd, &all);
	maxfd = sockfd;
	while (1)
	{
		rfds = wfds = all;
		if (select(maxfd + 1, &rfds, &wfds, NULL, NULL) < 0)
			continue;
		if (FD_ISSET(sockfd, &rfds))
			accept_client(sockfd, &all, &maxfd, &wfds);
		for (i = 0; i < MAX_CLIENTS; i++)
		{
			if (g_clients[i].fd == -1)
				continue;
			if (FD_ISSET(g_clients[i].fd, &rfds))
				handle_client(i, &all, &wfds);
		}
	}
	return (0);
}
