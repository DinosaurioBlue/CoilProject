#include<draw.h>


void draw(int x, int y, char * str){//this function should print whichever streen you send it
    int i,j;
    for(i=0;i<=HEIGHT;++i){
        for(j=0;j<=LENGHT;++j){
            if((i==0)||(i==HEIGHT)){
                mvaddchstr(i,j,"#");
            }
            else{
                mvaddchstr(i,j,"#");
                j=63;
            }

        }
    }
    mvaddstr(y,x,str);
}




void killscr(void){// this function is used to kill the screen
    erase();
}