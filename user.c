#include<stdio.h>
#include<string.h>

#define USERNAME_LENGHT 50
#define USERS_MAX 100

void login(user_t* name);
void UpdateScore(user_t* name, int);


typedef struct{
    char username[USERNAME_LENGHT];
    int score;
}user_t;


void UpdateScore(user_t* name, int points){
    //points is the name of the variable that contains the score of the player
    name->score+=points;
    //store the score corresponding to each player 
}

void Login(user_t* name){
    printf("Enter username: ");
    fgets(name->username, USERS_MAX, stdin);//reads the input of the user
    size_t len = strlen(name->username); //checks the lenght of the string the user entered
    if(len > 0 && name->username[len-1] == '\n'){
        name->username[len-1] = '\0'; 
        //to make sure the username doesn't include '\n'
    }
}

void History(user_t players[], int count){
    int i;
    
    FILE *file = fopen("history.txt", "a");
    
    for(i=0; i<count; i++){
        fprint(file, "USER: %s, SCORE:%d\n", players[i].username, players[i].score);
        //storing the username and their score in a .txt file
    }
    fclose(file);
}