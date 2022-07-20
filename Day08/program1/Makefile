CC=gcc

.PHONY: all
all:program

program: main.o hello.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o program