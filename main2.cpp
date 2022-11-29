#include "MyMenuBoard.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // StudentList.dat 파일을 읽기
    MenuBoard std;
    char *pathname = (char *)"./MenuBoardList.dat";

    list<MenuBoard> StudentList;
    list<MenuBoard>::iterator it;

    int fd = open(pathname, O_RDONLY); //.dat파일 오픈
    struct stat fileInfo;
    fstat(fd, &fileInfo);

    for (int i = 0; i < fileInfo.st_size / sizeof(MenuBoard); i++) {
        // FIFO방식으로 Menu 정보를 자료구조에 대입
        read(fd, &std, sizeof(MenuBoard));
        StudentList.push_back(std);
    }

    cout << "[Menu]\t[Score]\t[Price]" << endl;
    for (it = StudentList.begin(); it != StudentList.end(); it++) {
        cout << it->getName() << "\t  " << it->getoption() << "\t  "
             << it->getprice() << endl;
    }

    printf("   ---show %ld menu---\n", StudentList.size());
}