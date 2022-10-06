#include <kernel/types.h>
#include <user/user.h>

int main(int argc, char* argv[])
{
	/*
	 * check if arguments correct
	 */
	if(argc > 1){
		fprintf(2,"Usage: pingpong \n");
		exit(1);
	}

	/*
	 * create pipe
	 */
	int fd[2];
	char buf[100] = "ping-pong";
	int n = 0;

	if(pipe(fd)<0){
		fprintf(2,"Error: create pipe failed!\n");
		exit(1);
	}
	
	/*
	 * create process
	 */
	int pid = fork();
	if(pid < 0){
		fprintf(2,"Error: create process failed!\n");
		exit(1);
	}

	/*
	 * son: 	read byte, print, write byte
	 * parent:	write byte, wait, read byte, print
	 */
	if(pid == 0){
		while(n == 0){
			n = read(fd[0], buf, sizeof(buf));
		}
		printf("%d: received ping\n",getpid());
		write(fd[1], buf, 10);
		exit(0);
	}
	else{
		write(fd[1], buf, 10);
		wait((int*)0);
		while(n == 0){
			n = read(fd[0], buf, sizeof(buf));
		}
		printf("%d: received pong\n",getpid());
		exit(0);
	}
}

