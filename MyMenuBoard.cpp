#include "MyMenuBoard.h"
#include <string.h>
#include <string>

using namespace std;

MenuBoard::MenuBoard()
{
    memset(this->name, 0x00, MAX_NAME_LEN + 1);
    this->option = -1.0;
    this->price = -1;
}

MenuBoard::MenuBoard(string name, double option, int price)
{
    this->price = price;
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
    this->option = option;
}
void MenuBoard::setprice(int price) { this->price = price; }

void MenuBoard::setName(string name)
{
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
}

void MenuBoard::setoption(double option) { this->option = option; }
int MenuBoard::getprice(void) { return this->price; }
string MenuBoard::getName(void) { return string(this->name); }
double MenuBoard::getoption(void) { return this->option; }