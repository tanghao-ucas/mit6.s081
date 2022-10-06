#Lab 1: Xv6 and Unix utilities

## Boot xv6 (easy)
follow the lab instruction

## sleep (easy)
Implement the UNIX program 'sleep' for xv6;
Your 'sleep' should pause for a user-specified number of ticks
+ A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip.

Your solution should be in the file 'user/sleep.c'

## pingpong (easy)
Write a program that uses UNIX system calls to "ping-pong" a byte between two processes over a pair of pipes, one for each direction.
Here is the order:
+ parent: send byte to child
+ child: read byte, print "<pid>: received ping", write byte to parent
+ parent: read byte, print "<pid>: received pong" 

Your solution should be in the file 'user/pingpong.c'
