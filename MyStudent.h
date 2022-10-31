#ifndef __MYSTUDENT_H__
#define __MYSTUDENT_H__
#include <string>
#define MAX_NAME_LEN 32

using namespace std;

class Student {
  public:
    Student();
    Student(string name, double score, int id);
    void setId(int id);
    void setName(string name);
    void setScore(double score);
    
    int getId(void);
    string getName(void);
    double getScore(void);
    
  private:
    int id;
    char name[MAX_NAME_LEN + 1];
    double score;
};
#endif
    