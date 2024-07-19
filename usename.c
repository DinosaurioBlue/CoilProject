/*login function, saves a new username and their score to a file*/

#include<stdio.h>
#include"username.h"

#define NAME_MAX 30

/* main function to test the login function 

int main(void){
	login(20);
	return 0;
}

*/

void login(int score){
	char player[NAME_MAX];
	char countLine[NAME_MAX];
	int count = 1;
	
	
	FILE* pFile;//pointer to a file
	FILE* pRead;
	
	
	printf("Enter your name: "); //asks for the username
	scanf("%s", player);
	
	pFile = fopen("history.txt", "a"); //opens file
	pRead = fopen("history.txt", "r");
	
	
	if(pFile == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
	//keep track of the number of users logged in 
	//reads how many lines are in the file 	
	while(fgets(countLine, sizeof(countLine), pRead) != NULL){
		count++;
	}
		
	fprintf(pFile, "USER %d: %s SCORE: %d\n", count, player, score); //writes the username and score into the file 
	fclose(pFile);//closes the file 
}


