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

        string name = "";
        cout << "<< Menu Name: (input \'q\' to terminate): ";
        cin >> name;

        if (name.compare("q") == 0) {
        cout << ">> Terminate input." << endl; 
        break;
        }

        double score = -1.0;
        cout << "<< Option: ";
        cin >> score;
        if (score > 4 && score < 1) {
        cout << ">> Please Input 1 to 4." << endl; 
        break;
        }

        string input;
        cout << "<< Price: ";
        cin >> input;


        int id = stoi(input);

        Student stu(name, score, id);
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