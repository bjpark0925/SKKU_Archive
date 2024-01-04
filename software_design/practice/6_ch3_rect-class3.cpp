#include <iostream>
using namespace std;

class Rectangle
{
    // private:
    int width = 1, height = 1;

public:
    Rectangle() {};
    Rectangle(int w, int h);
    Rectangle(int length);
    bool isSquare();
};

// Rectangle::Rectangle() : Rectangle(1, 1) {} // 위임 생성자 delegating constructor
// Rectangle::Rectangle() {}
Rectangle::Rectangle(int a, int b) : width(a), height(b) {} // 타겟 생성자 target constructor
Rectangle::Rectangle(int a) : Rectangle(a, a) {}
bool Rectangle::isSquare()
{
    cout << "width: " << width << " height: " << height << endl;
    if (width == height)
        return true;
    return false;
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