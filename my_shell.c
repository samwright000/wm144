#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Splits the string by space and returns the array of tokens
*
*/
char **tokenize(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}

int cat(char **tokens){

	int pid;
	printf("%s",tokens[1]);
	pid = fork();

	if (pid == 0){
	
		execlp("cat","cat",tokens[1]);
	//	execlp(tokens[0],tokens[0],tokens[1]);
	//	execlp(tokens);	
	
	}

	else{
	
		wait(NULL);
		printf("\nDone Cat!\n");
	
	
	}

}

int ls(char **tokens){

	int i;
	
	for (i=0;i<=sizeof(tokens);i++){printf("\nToken[%d] = %s",i,tokens[i]);}
	
	int pid = fork();
	
		printf("\npid - %d\n",pid);


		if (pid == 0){
			execlp(tokens[0],tokens[0],tokens[1]);
		
		}

		else{
		
			wait(NULL);
			printf("\nDone ls!\n");
		}
}

int echo(char **tokens){
	int i;	
	int pid = fork();

	if (pid == 0){
		printf("\n");
		//for (i=1;tokens[i] != NULL;i++){printf("%s ",tokens[i]);}

	printf("\n");	
	}

	else{
		wait(NULL);
		printf("\nDone echo!\n");
	}

}


int cd(char **tokens){

	chdir(tokens[1]);

}



int main(int argc, char* argv[]) {
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;


	while(1) {			
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");
		scanf("%[^\n]", line);
		getchar();

		printf("Command entered: %s (remove this debug output later)\n", line);
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);
   
       //do whatever you want with the commands, here we just print them

		for(i=0;tokens[i]!=NULL;i++){
			printf("found token %s (remove this debug output later)\n", tokens[i]);
		}
		
		for (i=0;i<=sizeof(tokens);i++){printf("\nToken[%d] = %s",i,tokens[i]);}
		printf("\n\n");
		
		printf("\n\n%d\n\n",strcmp(tokens[0],"ls"));

		if (strcmp(tokens[0],"ls")==0){

			ls(tokens);
		
		
		
		}	// if this doesnt work as well might be better to fork here rather than in the function it self
		if (strcmp(tokens[0],"cat")==0){
		
			cat(tokens);
		
		}


		if (strcmp(tokens[0],"echo")==0){
		
			echo(tokens);
		
		
		}

		if (strcmp(tokens[0],"cd")==0){
		
			cd(tokens);
		
		}

		//execlp(tokens);

		// Freeing the allocated memory	
		for(i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);

	}
	return 0;
}
