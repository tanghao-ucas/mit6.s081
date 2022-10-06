#include <kernel/types.h>
#include <user/user.h>

int main(int argc, char* argv[])
{
	/*
	 * check if amount of argument correct
	 */
	if(argc <= 1 || argc >= 3){
		fprintf(2,"Usage: sleep ticks \n");
		exit(1);
	}

	/*
	 * sleep ticks
	 */
	int time = atoi(argv[1]);
	if(time < 0){
		fprintf(2,"sleep: ticks is invalud\n");
		exit(1);
	}
	sleep(time);
	exit(0);
}	
