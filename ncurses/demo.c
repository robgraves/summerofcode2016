
//demo.c
//Something something dark side...

#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main()
{
    int x           = 0;
    int y           = 0;
    int max_x       = 0;
    int max_y       = 0;
    int next_x      = 0;
    int direction   = 1;

    initscr();              //Initialize the window
    noecho();               //Don't echo any keypresses
    curs_set(FALSE);        //Don't display a cursor


    while(1)
    {
        //Global var 'stdscr' is created by the call to 'initscr()'
        getmaxyx(stdscr, max_y, max_x);

        clear();            //clear screen of previously printed characters
        mvprintw(y,x, "o"); //Print our "ball" at the current xy position
        refresh();

        usleep(DELAY);      //Shorter delay between movements

        next_x = x + direction;

        if (next_x >= max_x || next_x < 0)
        {
            direction *= -1;
        }
        else
        {
            x += direction;
        }
    }

    endwin();               //Restore normal terminal behavior
}
