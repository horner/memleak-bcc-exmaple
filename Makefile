
all:
	cc -o memleak-thread-example memleak-thread-example.c -lpthread
	cc -o memleak-example memleak-example.c -lpthread
