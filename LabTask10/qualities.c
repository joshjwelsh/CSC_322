#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

typedef char String[MAX_LENGTH];


void myEcho(){
	String sOutput;
	FILE *myFile;
	myFile = fopen("myQualities.txt", "r");
	if(myFile != NULL){
		fscanf(myFile,"%[^\n]",sOutput);
		printf("%s", sOutput);
		if(remove("myQualities.txt") == 0){
			printf("myQualities.txt was deleted!\n");
		}else{
			printf("Error when deleting the file\n");
		}
	}else{
		perror("There was an error opening the file!\n");
	}
		
}

int main(void){

String newStr = "The qualities are ";
FILE * myFile;
String * ptr; 
String test = "I am ";

myFile = fopen("myQualities.txt","w");
if(myFile == NULL){
    perror("There was an error openning the file");
}

for(;;){
	String str;

	if(fgets(str, MAX_LENGTH, stdin) != NULL){
	if(strcmp(str,".\n") == 0){
	    break;
	}    
	ptr = (String* )strstr(str,test);
	if(ptr != NULL){
	    String temp;
	    strncpy(temp, &str[4], (strlen(str) - 5));
		strcat(temp, ", ");
	    strcat(newStr, temp);
	}
    }
}
printf("Final Str: %s\n", newStr);
fprintf(myFile, "%s.", newStr);

fclose(myFile);

myEcho();

return 0;
}

