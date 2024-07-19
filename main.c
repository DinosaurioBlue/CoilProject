#include<stdio.h>
#include<unistd.h>
#include<curses.h>
#include<time.h>
#include<stdlib.h>
#include"draw.h"
typedef struct
{int x;
int y;
}vector_t;
vector_t dir ={1,0};
vector_t pos ={1,1};
int pressed;
char head[2]="*";


void main (void){
    WINDOW* win = initscr();
    keypad(win,true);
    nodelay(win,true);
    while (1)
    {
        pressed=wgetch(win);
        switch (pressed){
            case KEY_DOWN: dir.y =1; dir.x=0;break;
            case KEY_UP: dir.y =-1; dir.x=0;break;
            case KEY_RIGHT: dir.y =0;dir.x=1;break;
            case KEY_LEFT: dir.y =0; dir.x=-1;break;
            default: break;
        }
        pos.x +=dir.x;
        pos.y +=dir.y;
        erase();
        draw(pos.y,pos.x,"X");
        cleanscr()
        usleep(100000);
    }
    
    endwin();

}
void draw(int x, int y, char * str){//this function should print whichever streen you send it
    int i,j;
    /*for(i=0;i<=HEIGHT;++i){
        for(j=0;j<=LENGHT;++j){
            if((i==0)||(i==HEIGHT)){
                mvaddstr(i,j,"8");
            }
            else{
                mvaddstr(i,j,"8");
                j=63;
            }

        }
    }
    */
    mvaddstr(y,x,str);
}




void cleanscr(void){// this function is used to kill the screen
    erase();
}