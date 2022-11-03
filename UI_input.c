#include <ncurses.h>

int main() {

    initscr(); // Start nCurses window

    WINDOW *window1;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(40, 90, 0, 0);

    box(window1, 0, 0);

    mvwprintw(window1, 2, 1,
              "Menu name (Input 'q' to terminate, input 'c' to clear screen) : "
              "________________");
    mvwprintw(window1, 3, 1, "Menu price : _______");
    mvwprintw(window1, 4, 1, "Successfully added to list!");
    mvwprintw(window1, 5, 1,
              "Menu name (Input 'q' to terminate, input 'c' to clear screen) : "
              "________________");
    mvwprintw(window1, 6, 1, "Menu price : _______");
    mvwprintw(window1, 7, 1, "Successfully added to list!");
    mvwprintw(window1, 8, 1, "Terminate input");
    mvwprintw(window1, 9, 1,
              "2 foods' info was successfully saved to the ./food.dat");

    wbkgd(window1, COLOR_PAIR(1));

    wrefresh(window1);

    getch();
    endwin(); // End window
    return 0;
}
