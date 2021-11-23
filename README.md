# memleak-bcc-exmaple

Testing memleaks with [/usr/share/bcc/tools/memleak](https://github.com/iovisor/bcc/blob/master/tools/memleak.py)

Prerequsites:
```
sudo yum install perf bcc-tools gawk kernel-devel
```

output:
```
$ ./test.sh
cc -o memleak-thread-example memleak-thread-example.c -lpthread
cc -o memleak-example memleak-example.c -lpthread
Simple test
Launched ./memleak-example as 986697
/usr/share/bcc/tools/memleak -p 986697 -a
Attaching to pid 986697, Ctrl+C to quit.
Leaked!
[04:10:13] Top 10 stacks with outstanding allocations:
	addr = 12c92a0 size = 100
	addr = 12c9310 size = 1024
	100 bytes in 1 allocations from stack
		badfun+0x18 [memleak-example]
		main+0x3e [memleak-example]
		__libc_start_main+0xf3 [libc-2.28.so]
		[unknown]
	1024 bytes in 1 allocations from stack
		_IO_file_doallocate+0x90 [libc-2.28.so]
Leaked!
Leaked!
[04:10:18] Top 10 stacks with outstanding allocations:
	addr = 12c92a0 size = 100
	addr = 12c9720 size = 100
	addr = 12c9790 size = 100
	addr = 12c9310 size = 1024
	300 bytes in 3 allocations from stack
		badfun+0x18 [memleak-example]
		main+0x3e [memleak-example]
		__libc_start_main+0xf3 [libc-2.28.so]
		[unknown]
	1024 bytes in 1 allocations from stack
		_IO_file_doallocate+0x90 [libc-2.28.so]
Leaked!
Leaked!
Exiting with leaks
[04:10:23] Top 10 stacks with outstanding allocations:
	addr = 12c92a0 size = 100
	addr = 12c9870 size = 100
	addr = 12c9720 size = 100
	addr = 12c9790 size = 100
	addr = 12c9800 size = 100
	addr = 12c9310 size = 1024
	500 bytes in 5 allocations from stack
		[unknown]
		[unknown]
		[unknown]
		[unknown]
	1024 bytes in 1 allocations from stack
		[unknown]
[04:10:28] Top 10 stacks with outstanding allocations:
```
