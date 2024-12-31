#include <ncurses.h>
#include <sys/ioctl.h>
#include <time.h>
#include <stdlib.h>

#define DELAY 100
#define DELAY_BOOM 200

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void clearScreen(int lines, int cols){
    clear();
    mvprintw(lines / 2, cols / 2 - 8, "Happy New Year!!!");
}

void initDisplay(int *lines, int *cols){
    initscr();
    //printf("\33[?25l");
    curs_set(0);
    srand(time(NULL));
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    *lines = w.ws_row;
    *cols = w.ws_col;
}


void exitDisplay(){
    printf("\33[?25h");
    endwin();
}
