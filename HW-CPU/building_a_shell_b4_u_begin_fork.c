#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdint.h>


int main(){
/*
	int pid = fork();

	if (pid == 0){
	
		printf("I am the child, I have an ID of: %d\n",getpid());
	}

	else {
	
		wait(NULL); //will block parent process until any of its children has finished 
		printf("I am the Parent, I have an ID of: %d\n",getpid());
		
	
	}

*/
	char dir[64] = "/home/csc/wm144/HW-CPU";
	printf("%s\n\n\n\n\n\n\n\n",getcwd(dir,sizeof(dir)));

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>

struct stat statbuf;
struct dirent *dp;
struct stat *s;



DIR *dirp;
dirp = opendir("/home/csc/wm144/HW-CPU");

while((dp = readdir(dirp)) !=NULL)
{

    stat(dp->d_name, &statbuf);
    printf("%s - %jd", dp->d_name, (intmax_t)s->st_size);}
	return 0;


}
