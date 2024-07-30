/*signUp function, saves a new username to a file*/

#include<stdio.h>
#include<string.h>
#include"username.h"

#define NAME_MAX 30

//this function signs up new players
void signUp(void){
	char player[NAME_MAX];
	FILE* pFile;//pointer to a file

	
	printf("Enter your name: "); //asks for the username
	scanf("%s", player);
	
	pFile = fopen("history.txt", "a+"); //opens file
	if(pFile == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
	fprintf(pFile, "USER:%s SCORE:0\n", player); 
	//writes the username and the score into the file 
	fclose(pFile);//closes the file 
	
	/*
	PLAY FUNCTION
	SCORE OF PLAYER
	*/
	
	updateScore(500, player);
	
}

//this function checks if the player already exists and they log in with previous score
void login(void){
	char exist_player[NAME_MAX];
	char line[200];
	char username[NAME_MAX];
	int found = 0;
	FILE *pCheck;
	
	printf("Write your username: ");
	scanf("%s", exist_player);
	
	pCheck = fopen("history.txt", "r");
	if(pCheck == NULL){ //checks if the file exists
		perror("Error opening file");
	}
	
	while(fgets(line, sizeof(line), pCheck) != NULL){
		//extracts the username
		extractUsername(line, username);
		
		if(strcmp(exist_player, username) == 0){
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
		/*
		PLAY FUNCTION
		SCORE OF PLAYER
		*/
		updateScore(100, exist_player);
	}
	
}


void extractUsername(char *line, char *username) {
    char *start = strstr(line, "USER:"); // Find the start of username
    char *end;
    if (start != 0) {
        start += 5; // Skip "USER:"
        end = strstr(start, " SCORE:"); // Find the end of username
        if (end != 0) {
            size_t len = end - start;
            strncpy(username, start, len);
            username[len] = '\0'; 
        }
    }
}









void updateScore(int score, const char *player){
//	unsigned long int byte = sizeFile();
	char buffer[200];
	char *scorePosition;
	unsigned long int position;
	FILE *pChange = fopen("history.txt", "r+");
	
	if(pChange == NULL){
		perror("Failed to open file");
	}
	
//read each line and if it encounters the name of the player it changes their score to the udated one
	while(fgets(buffer, sizeof(buffer), pChange) != NULL){
		if(strstr(buffer, player) != NULL){
			position = ftell(pChange);
			scorePosition = strstr(buffer, "SCORE:");
			
			if(scorePosition != 0){
				fseek(pChange, position - strlen(buffer) + (scorePosition - buffer) + 6, SEEK_SET);
				fprintf(pChange, "%-4d\n", score);
			}
		}
	}
	
	fclose(pChange);
}
	

//determines how many bytes are in a file	
/*unsigned long int sizeFile(void){
	unsigned long int size;
	FILE *ptr = fopen("history.txt", "rb");
	
	if (ptr == NULL) {
    	perror("Failed to open file");
	}

	if (fseek(ptr, 0, SEEK_END) != 0) {
    	perror("Failed to seek to end of file");
    	fclose(ptr);
    }

	size = ftell(ptr);
	fclose(ptr);
	
	return size;
}
*/



	
	
	
	
	
	
	
	
	

