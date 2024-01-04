#include <iostream>
#include <string>
using namespace std;
class Point
{
    int x, y;

public:
    Point(int _x, int _y)
    {
        setXY(_x, _y);
    }
    void setXY(int _x, int _y) { x = _x; y = _y; }
    void getXY(int &_x, int &_y) { _x = x; _y = y; }
    void showXY()
    {
        cout << x << ", " << y << endl;
    }
};
class ColorPoint : public Point
{
    string color;
public:
    ColorPoint(int _x=0, int _y=0, string c="r")
    : Point(_x, _y)
    {
        color = c;
    }
    void getXYC(int& _x, int& _y, string& c)
    {
        getXY(_x, _y);
        c = color;
    }
    void setXYC(int _x, int _y, string c)
    {
        setXY(_x, _y);
        color = c;
    }
    void showXYC()
    {
        cout << color << ": ";
        showXY();
    }
};

int main()
{
    ColorPoint a;
    a.showXYC();

    a.setXY(5, 5);
    a.showXYC();

    ColorPoint b(10, 10, "g");
    b.showXYC();

    int x, y;
    string color;
    b.getXYC(x, y, color);

    ColorPoint c;
    c.setXYC(x, y, color);
    c.showXYC();
}