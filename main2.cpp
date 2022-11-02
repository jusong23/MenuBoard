#include "MyStudent.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // StudentList.dat 파일을 읽기
    Student std;
    char *pathname = "./StudentList.dat";

    int fd = open(pathname, O_RDONLY);
    struct stat fileInfo;
    fstat(fd, &fileInfo);

    for (int i = 0; i < fileInfo.st_size / sizeof(Student); i++) {
        read(fd, &std, sizeof(Student));
        cout << "Menu : " << std.getName() << " Score : " << std.getScore()
             << " Price : " << std.getId() << endl;
    }
    printf("show %ld menu\n", fileInfo.st_size / sizeof(Student));
}
