
all:
	cc -o memleak-thread-example memleak-thread-example.c -lpthread
	cc -o memleak-example memleak-example.c -lpthread

LeakSanitizer:  Makefile memleak-example.c
	gcc -fsanitize=leak -o LeakSanitizer memleak-example.c

valleak: Makefile memleak-example.c
	gcc -g -o valleak memleak-example.c
	valgrind --leak-check=full ./valleak
