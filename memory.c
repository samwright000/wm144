#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	char *heap = malloc(20);
	*heap = 0x61;

	printf("heap pointing to: 0x%x\n",*heap);
	free(heap);
	
	char *foo = malloc(20);

	*foo = 0x62;

	printf("foo pointing to: 0x%x\n",*foo);

	*heap = 0x63;
	printf("or is it pointing to: 0x%x\n",*foo);

	return 0 ;


}




/*
void zot(unsigned long *stop){

	unsigned long r = 0x3;

	unsigned long *i;

	for (i = &r; i <=stop; i++){
		printf(" %p 0x%lx\n",i,*i);
	
	}


}

void foo (unsigned long *stop) {

	unsigned long q = 0x2;

	zot(stop);

}

int main(){
	
	int pid = getpid();

	unsigned long p = 0x1;

	foo(&p);

back:

	printf("p: %p \n",&p);

	printf("back: %p \n", &&back);

	printf("\n\n /proc/%d/maps \n\n",pid);

	char command[50];

	sprintf(command, "cat /proc/%d/maps",pid);

	system(command);

	return 0 ;
*/

/*
foo: 

	printf("\nThe code: %p\n",&&foo);

	fgetc(stdin);
	
	return 0; 
}

char global[] = "This is a global string";
const int read_only = 12345;

int pid = getpid();

foo:

printf("process id: %d\n",pid);
printf("global string: %p\n",&global);
printf("the code: %p\n",&&foo);
printf("read_only: %p\n",&read_only); 


printf("\n\n /proc/%d/maps \n\n",pid);

char command[50]; 

sprintf(command,"cat /proc/%d/maps",pid);

system(command);

return 0;

int pid = getpid();

unsigned long p = 0x1;

printf(" p (0x%lx): %p \n",p,&p);

printf("\n\n /proc/%d/maps \n\n", pid);

char command[50];

sprintf(command,"cat /proc/%d/maps",pid);
system(command);

*/

