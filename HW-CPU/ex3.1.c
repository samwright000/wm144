#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

	int pid = fork();

	if (pid == 0){
		int child = getpid();
		printf("im the child %d with parent %d\n",child, getpgid(child));
	}

	else {
		int parent = getpid();
		printf("im the parent %d with parent %d\n",parent, getpgid(parent));
		wait(NULL);

	}

	return 0;
}
