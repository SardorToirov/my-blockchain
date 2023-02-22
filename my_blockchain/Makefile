CC = gcc
CFLAGS =  -Wall -Wextra -Werror
SOURCES = my_blockchain.c read_str.c my_readline.c my_split.c my_sort_flag.c
TARGET = my_blockchain

$(TARGET):$(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ 
 
.PHONY: fclean

fclean:
	@rm -r $(TARGET)
