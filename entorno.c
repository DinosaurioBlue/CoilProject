//design of the board game. 64x64

#include<stdio.h>

#define COLS 64
#define ROWS 64

char tablero[COLS*ROWS];

void ImprimirTablero();
void FillTablero();

int main(void){
    FillTablero();
    ImprimirTablero();
    return 0;
}



void ImprimirTablero(void){
    int x, y;

    for(y=0; y<ROWS; y++){
        for(x=0; x<COLS; x++){
            printf("%c", tablero[y*COLS + x]);
        }
        printf("\n");
    }
}

void FillTablero(void){
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(i==0 || j==0 || i== ROWS-1 || j== COLS-1){
                tablero[i*COLS + j] = '#';
            }
            else{
                tablero[i*COLS + j] = ' ';
            }
        }
    }
}