#include <iostream>
using namespace std;

int main()
{
    
    int width, height, area;
    cout<<"너비를 입력하세요>>";
    cin>>width;
    cout<<"높이를 입력하세요>>";
    cin>>height;
    area = width * height;
    cout << "\n면적은 " << area << endl;

    return 0;
}