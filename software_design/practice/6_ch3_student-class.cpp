#include <iostream>
using namespace std;

class Student
{
    int year, id, grade;

public:
    Student() {}                                               //;
    Student(int y, int i, int g) : year(y), id(i), grade(g) {} //;
    void setData(int y, int i, int g);
    void showData();
};
// setData는 서두 형식으로 작성할 수 없다.
void Student::setData(int y, int i, int g)
{
    year = y;
    id = i;
    grade = g;
}
void Student::showData()
{
    cout << "Year: " << year << " ID: " << id << " Grade: " << grade << endl;
}

int main()
{
    Student s;
    s.setData(2017, 100100, 1);
    s.showData();

    Student s1(2017, 100100, 1);
    s.showData();
    return 0;
}