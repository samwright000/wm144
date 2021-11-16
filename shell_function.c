#include <stdio.h>
//Used for handling directory files
#include <dirent.h>
//For EXIT codes and error handling
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
printf("\ndoing ls\n");
ls();
printf("\ndone ls\n");
//echo();
//cat();
printf("\ndoing cd\n");
cd();
printf("\ndone cd\n");
printf("\ndoing ls\n");
ls();
printf("\ndone ls\n");

chdir("..");
execlp("ls","ls",NULL);

}

//char **tokens

int cd(){execlp("cd","cd","..");}

int cat(){

	int pid;

	pid = fork();

	if (pid == 0){
	
		execlp("cat","cat","test.txt");
	//	execlp(tokens[0],tokens[0],tokens[1]);	
	
	}

	else{
	
		wait(NULL);
		printf("Done Cat!");
	
	
	}
	

	/*
	char filename[100] = "test.txt";
	int c;
	FILE *file;
	file = fopen(char filename,"r");

	if (file){
	
	
		while ((c=getc(file))!=EOF)
			putchar(c);
		fclose(file);
	}


	*/
}



int ls(){

	int pid = fork();
	
		printf("\npid - %d\n",pid);
	
		

		if (pid == 0){
			execlp("ls","ls","-a");
			//execlp(tokens[0],tokens[0],tokens[1]);
		
		}

		else{
		
			wait(NULL);
			printf("Done ls!\n");
		}
}

//char **tokens
/*
int echo(){
	int i;	
	int pid = fork();

	if (pid == 0){
		

		for (i=1;tokens[i] != NULL;i++){
		
			printf("%s ",tokens[i]);
		
		
		}

	}

	else{
		
		wait(NULL);
		printf("Done echo!\n");
	}

}
*/

