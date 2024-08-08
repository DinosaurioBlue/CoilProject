//startGame function is the first thing before loggin in 
#include<stdio.h>
#include"username.h"
#include"start.h"

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
		else{
			printf("Invalid option, try again\n");
			checkPlayer();
		}	

	}
}


