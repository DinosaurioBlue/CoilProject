/*signUp function, saves a new username to a file*/

#include<stdio.h>
#include<string.h>
#include"username.h"

#define NAME_MAX 30

//this function signs up new players
void signUp(void){
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
		
	fprintf(pFile, "USER %d: %s\n", count, player); //writes the username into the file 
	fclose(pFile);//closes the file 
}

//this function checks if the player already exists and they log in with previous score
void login(void){
	char exist_player[NAME_MAX];
	char search[NAME_MAX];
	int found;
	FILE *pCheck;
	
	printf("Write your username: ");
	scanf("%s", exist_player);
	
	pCheck = fopen("history.txt", "r");
	
	if(pCheck == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
	while(fgets(search, sizeof(search), pCheck) != NULL){
		//compares two strings 
		if(strcmp(exist_player, search) == 0){
			found = 1;
		}
		else{
			found = 0;
		}
	}
	
	fclose(pCheck);
		
	if(found != 1){
		printf("User not found\n");
	}
	else{
		printf("great, welcome %s\n", exist_player);
	}
}





