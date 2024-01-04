#include <iostream>
using namespace std;

class Figure
{
public:
    int type; // type 0 -> circle, type 1 -> square
    int v;    // length
    Figure()
    {
        type = -1;
        v = 0;
    }
    double getAreaCircle() { return 3.14 * v * v; }
    double getAreaSquare() { return v * v; }
};

// implement setFigure
int setFigure(Figure &f)
{
    cout << "Enter type: ";
    cin >> f.type;
    cout << "Enter v: ";
    cin >> f.v;
    return f.type;
}
int main()
{
    double area;
    Figure f;
    if (setFigure(f) == 0)
        area = f.getAreaCircle();
    else
        area = f.getAreaSquare();
    cout << "Area: " << area << endl;

    return 0;
}