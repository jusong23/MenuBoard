#include "MyMenuBoard.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // MenuBoardList.dat 파일을 읽기
    MenuBoard std;
    char *pathname = "./MenuBoardList.dat";

    int fd = open(pathname, O_RDONLY);
    struct stat fileInfo;
    fstat(fd, &fileInfo);

    for (int i = 0; i < fileInfo.st_size / sizeof(MenuBoard); i++)
    {
        read(fd, &std, sizeof(MenuBoard));
        cout << "Menu : " << std.getName() << " Score : " << std.getoption()
             << " Price : " << std.getprice() << endl;
    }
    printf("show %ld menu\n", fileInfo.st_size / sizeof(MenuBoard));
}
