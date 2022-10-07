#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"

/*
 * from `user/ls.c`
 */
char *fmtname(char *path)
{
	static char buf[DIRSIZ+1];
	char *p;

	for(p = path+strlen(path); p >= path && *p != '/'; p--);
	p++;

	if(strlen(p) >= DIRSIZ)
		return p;
	memmove(buf, p, strlen(p));
	buf[strlen(p)] = 0;
	return buf;
}

/*
 * find files that match the pattern in the path
 */
void find(char *path, char *pattern)
{
	char buf[512], *p;
	int fd;
	struct dirent de;
	struct stat st;

	if((fd = open(path, 0)) < 0){
		fprintf(2, "find: cannot open %s\n", path);
		return;
	}

	if(fstat(fd, &st) < 0){
		fprintf(2, "find: cannot stat %s\n", path);
		close(fd);
		return;
	}

	switch(st.type){
		case T_FILE:
			if(strcmp(pattern, fmtname(path)) == 0){
				printf("%s\n", path); 
			}
			break;
		case T_DIR:
			if(strlen(path) + 1 + DIRSIZ + 1 > sizeof(buf)){
				printf("find: path too long\n");
				break;
			}
			strcpy(buf, path);
			p = buf + strlen(buf);
			*p++ = '/';
			while(read(fd,&de,sizeof(de)) == sizeof(de)){
				if(de.inum == 0 || strcmp(de.name, "..") == 0 || strcmp(de.name, ".") == 0)
					continue;
				memmove(p, de.name, DIRSIZ);
				p[DIRSIZ] = 0;
				find(buf, pattern);
			}
			break;
	}
	close(fd);
	return;

}

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(2, "Usage: find dir pattern\n");
		exit(1);
	}
	
	char *path = argv[1];
	char *pattern = argv[2];

	find(path, pattern);

	exit(0);
}
