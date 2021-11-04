#include <stdio.h>
#include <unistd.h>

int main(){

	int pid;
	int x = 123;
	pid = fork();

	if (pid==0){
	
		printf(" child: 	x is %d\n",x);
		x = 42;
		sleep(1);
		printf("child: 		x is %d\n",x);
		printf("child: 		x is %d and the address is 0x%p\n",x,&x);
	}

	else{
	
	
		printf(" mother: 	x is %d\n",x);
		x=13;
		sleep(1);
		printf("mother: 	x is %d\n",x);
		printf("child: 		x is %d and the address is 0x%p\n",x,&x);
		wait(NULL);
	}

	return 0;

}
