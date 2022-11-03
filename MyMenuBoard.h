#ifndef __MYMenuBoard_H__
#define __MYMenuBoard_H__
#include <string>
#define MAX_NAME_LEN 32

using namespace std;

class MenuBoard
{
public:
  MenuBoard();
  MenuBoard(string name, double option, int price);
  void setprice(int price);
  void setName(string name);
  void setoption(double option);

  int getprice(void);
  string getName(void);
  double getoption(void);

private:
  int price;
  char name[MAX_NAME_LEN + 1];
  double option;
};
#endif
