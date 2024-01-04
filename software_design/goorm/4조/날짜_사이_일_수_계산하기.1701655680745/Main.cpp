#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    // main()함수를 보고 필요한 위임생성자, 타겟 생성자, 복사 생성자 작성
    Date(int year) : Date(year, 1, 1) {}
    Date(int year, int month) : Date(year, month, 1) {}
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    Date(const Date &other)
    {
        year = other.year;
        month = other.month;
        day = other.day;
    }

    string printDate() const
    {
        return to_string(year) + "년 " + to_string(month) + "월 " + to_string(day) + "일";
    }

    int calcDifference(const Date &other) const
    {
        // int 형 변수 days1, days2를 선언하고 각 날짜의 일수를 구한 후 차이를 출력하는 함수
        // calcuateTotalDays() 이용
        int days1 = calculateTotalDays(year, month, day);
        int days2 = calculateTotalDays(other.year, other.month, other.day);
        if (days1 > days2)
        {
            return days1 - days2;
        }
        else
        {
            return days2 - days1;
        }
    }

    bool leapYear(int year) const
    { // 윤년 여부 출력
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int daysInMonth(int year, int month) const
    {
        const int daysInEachMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && leapYear(year))
        {
            return 29;
        }
        return daysInEachMonth[month];
    }

    int calculateTotalDays(int year, int month, int day) const
    {
        // 해당 날짜의 총 일수 계산하고 반환하는 함수
        // LeapYear(), daysInMonth() 이용
        int result = 0;
        for(int i = 1; i < year; i++)
        {
            if(leapYear(i))
            {
                result += 366;
            }
            else
            {
                result += 365;
            }
        }
        for (int i = 1; i < month; i++)
        {
            result += daysInMonth(year, i);
        }
        result += day;
        return result;
    }
};

int main()
{
    Date date1(2020);
    Date date2(2020, 1, 1);
    Date date3(2021);
    Date date4(2022, 9);
    Date date5(2022, 8);
    Date date6(2023, 12, 14);
    Date date7(2025, 8, 25);
    Date date8(2022, 9, 1);
    Date date9 = date1;
    Date date10 = date6;

    // 연도만 입력된 케이스끼리 비교, 0 출력 확인
    cout << date1.printDate() << ", " << date2.printDate() << "-> " << date1.calcDifference(date2) << "일" << endl;
    cout << date2.printDate() << ", " << date1.printDate() << "-> " << date2.calcDifference(date1) << "일" << endl;
    cout << date1.printDate() << ", " << date3.printDate() << "-> " << date1.calcDifference(date3) << "일" << endl;

    // 연도만 입력된 케이스, 연월이 입력된 케이스 비교 (+ 순서 바꿔서 양음 적용 확인)
    cout << date3.printDate() << ", " << date4.printDate() << "-> " << date3.calcDifference(date4) << "일" << endl;
    cout << date4.printDate() << ", " << date3.printDate() << "-> " << date4.calcDifference(date3) << "일" << endl;

    // 연월이 입력된 케이스, 연월일이 입력된 케이스 비교 (+ 순서 바꿔서 양음 적용 확인)
    cout << date5.printDate() << ", " << date6.printDate() << "-> " << date5.calcDifference(date6) << "일" << endl;
    cout << date6.printDate() << ", " << date5.printDate() << "-> " << date6.calcDifference(date5) << "일" << endl;

    // 연월일 입력된 케이스 두 개 비교 (+ 순서 바꿔서 양음 적용 확인)
    cout << date7.printDate() << ", " << date8.printDate() << "-> " << date7.calcDifference(date8) << "일" << endl;
    cout << date8.printDate() << ", " << date7.printDate() << "-> " << date8.calcDifference(date7) << "일" << endl;

    // 복사 생성자 이용한 객체들끼리 비교
    cout << date9.printDate() << ", " << date10.printDate() << "-> " << date9.calcDifference(date10) << "일" << endl;

    // 원형과 복사된 객체 비교
    cout << date1.printDate() << ", " << date9.printDate() << "-> " << date1.calcDifference(date9) << "일" << endl;

    return 0;
}