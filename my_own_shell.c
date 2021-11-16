#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(){

	char linearray[15][10];
	char word[10];

//	printf("line[0] = %s", line[0]);
//	printf("line[1] = %s", line[1]);
//	printf("line[2] = %s", line[2]);
	
	


	char line[100] = "ls -a";
	char command0[10];
	char command1[10];
	char command2[10];
	char command3[10];
	char command4[10];
	char command5[10];

	int i;
	int ii;
	int pos = 0;
	for (i=0;i<=strlen(line);i++){

		printf("line[%d] = %d\n",i,line[i]);
		printf("linearray[%d] = %s\n",i,linearray[i]);
		printf("linearray[%d] = %s\n",i,linearray[i]);


		if (line[i] != " "){

			*linearray[pos] = *linearray[pos]+line[i];
		
		}

		if (line[i] == " "){
		
			pos++;
		
		}
	}

	for (i=0;i<=15;i++){
	
		printf("\nlinearray[%d] = %d",i,*linearray[i]);
	
	}


	printf("\n\nword = %s\n\n",word);
	if (word == "place1"){
	
		printf("line[0] is equal to place 1");
	
	}
	while(1){

		printf("\n>>> ");
		scanf("%s",line);

		printf("\nDebug: User input = %s\n",line);
	
	}

}
