#include <iostream>
using namespace std;
// �ڵ� �ζ��� �Լ�: Ŭ���� ����ο� ������ ��� �Լ�(������ ����)
// inline ������ �ʿ� ���� �����Ϸ��� �ڵ� �ζ��� ó��
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
        cout << "rect1�� ���簢��" << endl;
    if (rect2.isSquare())
        cout << "rect2�� ���簢��" << endl;
    if (rect3.isSquare())
        cout << "rect3�� ���簢��" << endl;

    return 0;
}