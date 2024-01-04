#include <iostream>
using namespace std;
// 자동 인라인 함수: 클래스 선언부에 구현된 멤버 함수(생성자 포함)
// inline 선언할 필요 없이 컴파일러가 자동 인라인 처리
class Rectangle
{
    // private:
    int width, height;

public:
    Rectangle()
    {
        width = 1;
        height = 1;
    };
    Rectangle(int w, int h) : width(w), height(h){};
    Rectangle(int length) : Rectangle(length, length){};
    bool isSquare()
    {
        cout << "width: " << width << " height: " << height << endl;
        if (width == height)
            return true;
        return false;
    };
};

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