# Lab2: System calls
[Reference](https://pdos.csail.mit.edu/6.828/2021/labs/syscall.html)

Preparation
+ xv6 book: 				Chapter 2, Section 4.3, Section 4.4
+ user-space:				`user/user.h`, `user/usys.pl`
+ kernel-space: 		`kernel/syscall.h`, `kernel/syscall.c`
+ process-related: 	`kernel/proc.h`, `kernel/proc.c`  

## system call tracing (moderate)
Add a system call tracing feature that may help you when debugging later labs

Create a new `trace` system call that will control tracing

The `trace` system call takes one argument, an integer `mask`, whose bits specify which system calls to trace

You have to modify the xv6 kernel to print out a line when each system call is about to return, if the system's number is set in the mask.

The line should contain:
1. process id
2. the name of the system call
3. the return value

For example: `<pid>: syscall <syscall_name> -> <return_value>`

The `trace` system call should enable tracing for the process that calls it and any children that it subsequently forks, but should not affect other processes.

## sysinfo
Add a system call `sysinfo` that collects infomation about the running system

The system call takes one argument: a pointer to a `struct sysinfo`(see `kernel/sysinfo.h`)

The kernel should fill out the field of this `struct sysinfo`:
+ `freemem`	: the number of byte of current free memory
+ `nproc`   : the number of processes whose `state` is not `UNUSED`
