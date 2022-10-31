#include "MyStudent.h" 
#include <fcntl.h> 
#include <iostream> 
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(void) {

// 학생들의 정보를 입력받고, 연결 리스트에 저장 
list<Student> stuList;
while (1) {
        string input;
        cout << "<< ID (input \'q\' to terminate): ";
        cin >> input;
        if (input.compare("q") == 0) {
        cout << ">> Terminate input." << endl; break;
        }
        int id = stoi(input);
        string name = "";
        cout << "<< Name: ";
        cin >> name;
        double score = -1.0;
        cout << "<< Score: ";
        cin >> score;
        Student stu(id, name, score);
        stuList.push_back(stu);
        cout << ">> Successfully added to list!" << endl;
    }

// 입력된 학생들의 정보를 저장할 파일 열기
string filepath = "./StudentList.dat";

int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644); if (fd == -1) {
    perror("open() error");
return 1; }
// 학생들의 정보를 파일에 순차적으로 저장하기
list<Student>::iterator iter;
for (iter = stuList.begin(); iter != stuList.end(); ++iter) {
    if (write(fd, &(*iter), sizeof(Student)) == -1) {
        perror("write() error");
        return 2;
} }

cout << ">> " << stuList.size()
<< " students' info was successfully saved to the " << filepath << endl;

close(fd);

    return 0;
}

// cd "/Users/song._.327/Documents/Cplus/CC/HW1/HW1_2018734021/" && g++ -std=c++17 HW1_2018734021.cpp MyDoubleVector.cpp -o MyDoubleVector && "/Users/song._.327/Documents/Cplus/CC/HW1/"MyDoubleVector