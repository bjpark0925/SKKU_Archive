#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle();
    ~Circle(){};
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle()
{
    radius = 1;
}

int main()
{
    int n, radius;
    cout << "생성하고자 하는 원의 개수?";
    cin >> n;
    Circle *pArray = new Circle[n];
    for (int i = 0; i < n; i++)
    {
        cout << "원" << i + 1 << ":";
        cin >> radius;
        pArray[i].setRadius(radius);
    }
    int count = 0;
    Circle *p = pArray;
    for (int i = 0; i < n; i++)
    {
        double area = p->getArea();
        cout << area << ' ';
        if (area >= 100 && area <= 200)
        {
            count++;
        }
        p++;
    }

    cout << endl
         << "면적이 100에서 20 사이 원의 개수는 " << count << endl;

    delete[] pArray;

    return 0;
}