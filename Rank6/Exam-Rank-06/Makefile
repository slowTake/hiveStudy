CC       = cc
CFLAGS   = -Wall -Wextra -Werror
BUILD    = build

.PHONY: all test-mini_serv clean

all: test-mini_serv

test-mini_serv: $(BUILD)/mini_serv
	@echo "Reference compiled: $(BUILD)/mini_serv"
	@echo "Run: $(BUILD)/mini_serv <port>  then  nc 127.0.0.1 <port>"

$(BUILD)/mini_serv: mini_serv/reference/mini_serv.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) mini_serv/reference/mini_serv.c -o $@

clean:
	rm -rf $(BUILD)
