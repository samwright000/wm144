#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

	int pid = fork();

	if (pid == 0) {
	
	
		printf("i'm the child %d\n",getpid());
		sleep(1);
	}
	
	else {
	
		printf("my child is called %d\n",pid);

		wait(NULL);
		printf("my child has terminated	\n");
	}
	printf("this is the end (%d)\n",getpid());

	return 0;


}
