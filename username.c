/*signUp function, saves a new username to a file*/

#include<stdio.h>
#include<string.h>
#include"username.h"

#define NAME_MAX 30

//this function signs up new players
void signUp(void){
	char player[NAME_MAX];
//	char countLine[NAME_MAX];
//	int count = 1;
	
	
	FILE* pFile;//pointer to a file
	FILE* pRead;
	
	
	printf("Enter your name: "); //asks for the username
	scanf("%s", player);
	
	pFile = fopen("history.txt", "a"); //opens file
	pRead = fopen("history.txt", "r");
	
	
	if(pFile == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
/*	//keep track of the number of users logged in 
	//reads how many lines are in the file 	
	while(fgets(countLine, sizeof(countLine), pRead) != NULL){
		count++;
	}*/
		
	fprintf(pFile, "USER: %s  SCORE: 0\n", player); //writes the username and the score into the file 
	fclose(pFile);//closes the file 
	
	/*
	PLAY FUNCTION
	SCORE OF PLAYER
	*/
	
	void updateScore(points, player);
	
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
	/*
	PLAY FUNCTION
	SCORE OF PLAYER
	*/
	
	void updateScore(points, exist_player);
		
}


//this function updates the score of a player
void updateScore(int score, char *player){
	FILE *pFile;
	FILE *pTemp;
	char buffer[7000]; //stores every character in the file
	char temporary[100];
	int found = 0;
	
	pFile = fopen("history.txt", "r+");
	if(pFile == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
	pTemp = fopen("temporay.txt", "w");
	if(pTemp == NULL){ //checks if the file exists
		perror("Error opening file");
		fclose(file);
	}
	

	//read each line and if it encounters the name of the player, it modifies their score. It writes it into a temporay file 
	while(fgets(buffer, sizeof(buffer), pFile) != NULL){
		if(strstr(buffer, player) != NULL){
			sprintf(temporary, "USER: %s SCORE %d\n", player, score);
			fputs(temporary, pTemp);
			found = 1;
		}
		else{
			fputs(buffer, pTemp);			
		}
	}
	
	fclose(pFile);
	fclose(pTemp);
	
	//replaces original file with the updated content
	if(found != 0){
		remove("history.txt");
		rename("temporary.txt", "history.txt");
	}
	
}

