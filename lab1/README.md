# Lab 1: Xv6 and Unix utilities
[Reference](https://pdos.csail.mit/edu/6.828/2021/labs/util.html)

## Boot xv6 (easy)
follow the lab instruction

## sleep (easy)
Implement the UNIX program `sleep` for xv6

Your `sleep` should pause for a user-specified number of ticks
+ A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip.

Your solution should be in the file `user/sleep.c`

## pingpong (easy)
Write a program that uses UNIX system calls to "_ping-pong_" a byte between two processes over a pair of pipes, one for each direction.

Here is the order:
+ _parent_ : send byte to child
+ _child_  : read byte, print `<pid>: received ping`, write byte to parent
+ _parent_ : read byte, print `<pid>: received pong`

Your solution should be in the file `user/pingpong.c`

## primes (moderate/hard)
Write a concurrent version of prime sieve using pipes

This idea is dut to Doug Mcllroy, inventor of Unix pipes, the explaination are from [Here](https://swtch.com/~rsc/thread/)

Your solution should be in the file `user/primes.c`

## find (moderate)
Write a simple version of the UNIX find program:

+ find all the files in a directory tree with a specific name.
+ use recursion to allow find to descend into sub-directories
+ don't recurse into `.` and `..`

Your solution should be in the file `user/find.c`

## xargs (moderate)
Write a simple version of the UNIX xargs program:

+ read lines from the standard input
+ supply the line as additional argument to the new command
+ run a command for each line

Your solution should be in the file `user/xargs.c`
