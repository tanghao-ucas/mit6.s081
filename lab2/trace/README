1. Add `$U/_trace` to `UPROGS` in `Makefile`
2. Add system call prototye to `user/user.h`, a stub to `user/usys.pl`, a syscall number to `kernel/syscall.h`
3. Modify `proc` structure in `kernel/proc.h` for tracing
4. Add `sys_trace()` function in `kernel/sysproc.c` that implements the new system call
5. Modify `fork()` to copy the trace mask from parent to child process
6. Modify `syscall()` in `kernel/syscall.c` to print the trace infomation, which need a array of syscall name to index into.
