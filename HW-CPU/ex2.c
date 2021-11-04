#include <stdio.h>
#include <unistd.h>

int main(){

	int pid = fork();

	if (pid == 0) {
	
		printf("i'm the child %d\n",getpid());
	}

	else {
	
		printf("my child is called %d\n",pid);
	}

	printf("that's it %d\n", getpid());
	return 0;
	
}
