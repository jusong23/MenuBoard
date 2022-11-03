#include <ncurses.h>

int main() {

    initscr(); // Start nCurses window

    WINDOW *window1;
    WINDOW *window2;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(40, 60, 0, 0); // Menu screen, 40 * 60
    window2 = newwin(40, 25, 0, 60);

    box(window1, 0, 0);

    mvprintw(0, 28, "MENU"); // To place word at center of window
    mvwprintw(window1, 1, 15,
              "MENU  NAME"); // Menu name split in menu window, 40*40
    mvwprintw(window1, 1, 48,
              "PRICE"); // Menu price split in menu window, 40*20

    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(2));

    mvwvline(window1, 2, 39, '|', 37); // Line between menu and price

    mvprintw(1, 65, "Input menu");
    mvprintw(2, 65, "Name : __________");
    mvprintw(3, 65, "Price : _________");
    mvprintw(5, 73, "Input");

    mvprintw(10, 65, "Delete menu");
    mvprintw(11, 65, "Menu number : __");
    mvprintw(13, 73, "Delete");

    mvprintw(30, 73, "Home");

    // Food ex
    mvwprintw(window1, 2, 2, "1. Spaghetti");
    mvwprintw(window1, 3, 2, "2. Pizza");
    mvwprintw(window1, 4, 2, "3. Chicken");

    // Price ex
    mvwprintw(window1, 2, 41, "$9.90");
    mvwprintw(window1, 3, 41, "$14.90");
    mvwprintw(window1, 4, 41, "$11.90");

    wrefresh(window1);
    wrefresh(window2);
    getch();
    endwin(); // End window
    return 0;
}
