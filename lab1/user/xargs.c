#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
	/*
	 * store standard input
	 */
	char bufferIn[32];
	int InSiz = 0;

	char bufferOut[512];
	char *bufferPtr = bufferOut;
	int OutSiz = 0;
	
	/*
	 * store new command
	 */
	char *tokens[MAXARG];
	int tokenSiz = argc - 1;

	/*
	 * store the argument in the previous command into new command
	 */
	for(int i = 1; i < argc; ++i)
		tokens[i-1] = argv[i];
	/*	
	 * read input from standard input to buffer
	 * scan every single character
	 * 	copy non-key-characters into new command
	 * 	if necessary, fork a new process and execute
	 */  	
	while((InSiz = read(0, bufferIn, sizeof(bufferIn))) > 0){
		for(int i = 0; i < InSiz; i++){
			if(bufferIn[i] == ' '){
				bufferOut[OutSiz++] = 0;
				tokens[tokenSiz++] = bufferPtr;
				bufferPtr = bufferOut + OutSiz;
			}else if(bufferIn[i] == '\n'){
				bufferOut[OutSiz++] = 0;
				tokens[tokenSiz++] = bufferPtr;
				tokens[tokenSiz] = 0;

				if(fork() == 0){
					exec(argv[1], tokens);
				}else{
					wait((int*)0);
				}

				tokenSiz = argc - 1;
				OutSiz = 0;
			}else{
				bufferOut[OutSiz++] = bufferIn[i]; 
			}
		}		
	}
	exit(0);
}
