target = app
CC = gcc
CFLAGS = -std=c99
src = $(wildcard ./*.c)
obj = $(patsubst %.c, %.o, $(src))

$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) $< -o $@ $(CFLAGS) -c

.PHONY:clean
clean:
	rm -f $(target) $(obj)