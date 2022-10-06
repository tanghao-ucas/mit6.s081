#include <kernel/types.h>
#include <user/user.h>

/*
 * print prime
 */
void prime_print(int num)
{
	printf("prime %d\n",num);
}

/*
 * check all prime number in Array'data'
 */
int prime_check(int* data, int num)
{
	if(num <= 1) return 0;
	int prime = data[0];
	int cnt = 0;
	for(int i = 1; i < num; i++){
		if(data[i] % prime)
			data[cnt++] = data[i];
	}
	return cnt;
}

/*
 * create pipe & process
 * parent: write to pipe, wait
 * child : read from pipe, print, check, iter(if needed)
 */
void prime_son(int* data, int num)
{
	int fd[2];
	int pid;
	int n;
	pipe(fd);
	pid = fork();
	if(pid == 0){
		close(fd[1]);
		n = read(fd[0], data, sizeof(int)*num);
		prime_print(data[0]);
		n = prime_check(data, num);
	       	if(n == 0) exit(0);
		prime_son(data, n); 
	}
	else{
		close(fd[0]);
		write(fd[1], data, sizeof(int)*num);
		wait((int*)0);
		exit(0);
	}
}

/* 
 * first process to send prime
 */
int main(int argc, char* argv[])
{
	if(argc > 1){
		fprintf(2, "Usage: primes \n");
		exit(1);
	}

	int prime = 2;
	int next[35] = {0};
        int count = 0;	
	for(int i = 3; i <= 35; ++i){
		if(i % prime)
			next[count++] = i;
	}
	prime_print(prime);	
	prime_son(next, count);
	exit(0);
}

		
