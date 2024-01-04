#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;

    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);
    bool isSquare();
};

Rectangle::Rectangle()
{
    width = height = 1;
}
Rectangle::Rectangle(int a, int b)
{
    width = a;
    height = b;
}
Rectangle::Rectangle(int a)
{
    width = height = a;
}
bool Rectangle::isSquare()
{
    /*
    if (width == height)
        return true;
    return false;
    */
    return (width == height);
}

int main()
{
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if (rect1.isSquare())
        cout << "rect1은 정사각형" << endl;
    if (rect2.isSquare())
        cout << "rect2은 정사각형" << endl;
    if (rect3.isSquare())
        cout << "rect3은 정사각형" << endl;

    return 0;
}