FROM alpine:3.20.6

RUN apk update && apk add --no-cache \
	mariadb-client \
	php83 \
	php83-fpm \
	php83-phar \
	php83-curl \
	php83-mysqli \
	php83-iconv \
	php83-json \
	php83-mbstring \
	php83-xml \
	wget

# WP-CLI at BUILD time: keeps a slow/flaky campus network off the startup path
RUN wget -q https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
		-O /usr/local/bin/wp \
	&& chmod +x /usr/local/bin/wp

# PHP tuning baked in, so it is not re-appended on every container start
RUN printf 'memory_limit = 256M\nmax_execution_time = 120\n' >> /etc/php83/php.ini

COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf

RUN mkdir -p /var/www/html

COPY ./tools/wordpress-script.sh /usr/local/bin/wordpress-script.sh
RUN chmod +x /usr/local/bin/wordpress-script.sh

RUN addgroup -S www-data 2>/dev/null || true \
	&& adduser -D -H -s /sbin/nologin -g www-data -G www-data www-data

EXPOSE 9000

CMD ["wordpress-script.sh"]
