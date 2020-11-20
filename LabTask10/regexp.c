#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>


#define MAX_LENGTH 1024


int regex(char line[], char reg[]){
	regex_t regex;
	int regcom;
	
	regcom = regcomp(&regex, reg, 0);
	if(regcom){
		printf("Error compiling regex\n");
		exit(1);
	}
	regcom = regexec(&regex, line, 0, NULL, 0);
 	if(!regcom){
		return 0; // Match
	}else if (regcom == REG_NOMATCH){
		return 0; // 1 Fail
	}else{
		return 0; 
	}
	regfree(&regex);
}


int main(void){
	char sentence[MAX_LENGTH];
	char reg [MAX_LENGTH];
	char * line;
	char * idk = NULL;
	printf("Please enter the string to analyze: \n");
	scanf("%[^\n]",sentence );
	printf("Please enter the regular expression :\n");
	scanf("%s", reg);
	idk = sentence;
	while ((line = strtok_r(idk, ".!?", &idk) ))
	{
		int result;
		printf("%s\n", line);
		result = regex(line, reg);
		if(result == 0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
return 0;
}
