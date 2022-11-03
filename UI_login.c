#include <ncurses.h>

int main() {

    initscr(); // Start nCurses window

    WINDOW *window1;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(20, 25, 0, 0);

    box(window1, 0, 0);

    mvwprintw(window1, 1, 1, "USER : ________");
    mvwprintw(window1, 2, 1, "Connected !");
    mvwprintw(window1, 4, 1, "> Input menu");
    mvwprintw(window1, 5, 1, "> Edit menu");
    mvwprintw(window1, 10, 1, "Quit");

    wbkgd(window1, COLOR_PAIR(1));

    wrefresh(window1);

    getch();
    endwin(); // End window
    return 0;
}
