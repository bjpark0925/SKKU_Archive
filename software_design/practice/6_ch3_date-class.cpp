#include <iostream>
#include <string>
using namespace std;
// DateŬ���� �߰�
class Date
{
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d){};
    Date(string s);
    void show();
    bool olderThan(Date &d);
};
Date::Date(string s)
{
    int all = stoi(s);
    year = all / 10000;
    month = (all % 10000) / 100;
    day = all % 100;
}
void Date::show()
{
    cout << year << "��" << month << "��" << day << "��" << endl;
}
bool Date::olderThan(Date &d)
{
    if (year != d.year)
    {
        if (year < d.year)
            return true;
        else
            return false;
    }

    else if (month != d.month)
    {
        if (month < d.month)
            return true;
        else
            return false;
    }

    else if (day != d.day)
    {
        if (day < d.day)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    Date A(2014, 3, 20);  // 2014�� 3�� 20��
    Date B("19990815");   // yyyymmdd
    Date C("20140320");   // yyyymmdd
    Date D(2015, 11, 05); // 2015�� 11�� 55��
    A.show();
    B.show();
    C.show();
    D.show();
    cout << "A is older than B: " << A.olderThan(B) << endl;
    cout << "A is older than C: " << A.olderThan(C) << endl;
    cout << "A is older than D: " << A.olderThan(D) << endl;

    return 0;
}