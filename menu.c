//startGame function is the first thing before loggin in 
#include<stdio.h>
#include"score.h"
#include"menu.h"
#include"topscore.h"

char x;

void startGame(void){
	//the player will only be allowed to play if they press letter 's'  
	printf("SNAKE GAME  \nPress ENTER to start...\n");
	x = getchar();
	while(x != '\n' ){
		printf("Press ENTER to start\n");
		x = getchar();
	}
	checkPlayer();
}
	
void checkPlayer(void){
	if(x == '\n'){
		printf("Press 't' to see the scores\n");
		printf("Press 'l' if you already played\n");
		printf("Press 's' if you are new here\n");
		x = getchar();
		getchar();
		
		if(x == 'l'){
			login();
		}
		else if(x == 's'){
			signUp();
		}
		else if(x == 't'){
			top_score();		
		}
		else{
			printf("Invalid option, try again\n");
			checkPlayer();
		}	

	}
}


//this function signs up new players
void signUp(void){
	char trash[500];
	char player[NAME_MAX];
	int found = 0;
	FILE* pFile;//pointer to a file
	FILE* ptrCheck;

	
	printf("Enter your name: "); //asks for the username
	scanf("%s", player);
	
	ptrCheck = fopen("history.txt", "r");//pointer to check if the username already exists
	if(ptrCheck == NULL){
		perror("Error opening file");
	}	
	
	while(fgets(trash, sizeof(trash), ptrCheck) != NULL){
		//stores the text that reads in the .txt and then compares it to the player's name 
		if(strstr(trash, player) != NULL){
			found = 1;//user found
		}
	}
	
	fclose(ptrCheck);
	
	if(found != 1){
		pFile = fopen("history.txt", "a+"); //opens file
		if(pFile == NULL){ //checks if the file exists
			perror("Error opening file");
		}
	
		fprintf(pFile, "USER:%s SCORE:0\n", player); 
		//writes the username and the score into the file 
		fclose(pFile);//closes the file 
	}
	
	else{
		printf("Name already used. Choose another player: \n");
		signUp();
	}
	
	
	/*
	PLAY FUNCTION
	SCORE OF PLAYER
	*/
	
	
	updateScore(500, player);
	
}




//this function checks if the player already exists and they log in with previous score
void login(void){
	char player[NAME_MAX];
	char buffer[500]; 
	int log = 0;
	FILE *ptr = fopen("history.txt", "r");
	
	if(ptr == NULL){
		perror("Error opening file");
	} 
	
	printf("Enter yout username: ");
	scanf("%s", player);
	
	while(fgets(buffer, sizeof(buffer), ptr) != NULL){
		//stores the text that reads in the .txt and then compares it to the player name 
		if(strstr(buffer, player) != NULL){
			log = 1;//user found
		}
	}
	
	fclose(ptr);
	
	if(log!=0){
		printf("Welcome back %s\n", player);
	}
	else{
		printf("User not found. Please sign up\n");
		signUp();
	}
	
	/*
	PLAY FUNCTION
	SCORE OF PLAYER
	*/
	
	updateScore(568, player);
	
	
}











