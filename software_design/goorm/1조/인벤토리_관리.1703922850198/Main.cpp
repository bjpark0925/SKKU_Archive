#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string name; // 3순위(낮을수록 중요)
    int grade;   // 1순위(높을수록 중요)
    int price;   // 2순위(높을수록 중요)

public:
    Item() {}
    Item(string name, int grade, int price);
    ~Item();
    // ...
    void setName(string name) { this->name = name; }
    void setGrade(int grade) { this->grade = grade; }
    void setPrice(int price) { this->price = price; }
    string getName() { return name; }

    static int findExtremum(Item *inventory, int n, bool findMax)
    {
        int extremumGrade = inventory[0].grade;
        int extremumIndex = 0;

        for (int i = 1; i < n; ++i)
        {
            if ((findMax && inventory[i].grade > extremumGrade) ||
                (!findMax && inventory[i].grade < extremumGrade))
            {
                extremumGrade = inventory[i].grade;
                extremumIndex = i;
            }
            else if (inventory[i].grade == extremumGrade)
            {
                if (inventory[i].price > inventory[extremumIndex].price)
                {
                    extremumIndex = i;
                }
                else if (inventory[i].price == inventory[extremumIndex].price &&
                         inventory[i].name < inventory[extremumIndex].name)
                {
                    extremumIndex = i;
                }
            }
        }

        return extremumIndex;
    }
};

Item::Item(string name, int grade, int price)
{
    this->name = name;
    this->grade = grade;
    this->price = price;
    cout << grade << "등급 " << name << " 획득! " << endl;
}

Item::~Item()
{
    cout << grade << "등급 " << name << " 폐기.. " << endl;
}

int main()
{
    int n;
    cin >> n;
    Item *inventory = new Item[n];

    for (int i = 0; i < n; ++i)
    {
        string name;
        int grade, price;
        cin >> name >> grade >> price;
        inventory[i] = Item(name, grade, price);
    }

    while (true)
    {
        string name;
        cin >> name;

        if (name == "독버섯")
        {
            for (int i = 0; i < n; ++i)
            {
                int extremumIndex = Item::findExtremum(inventory, n, true);
                inventory[extremumIndex].~Item();
            }

            cout << "인벤토리가 사라집니다." << endl;
            break;
        }

        int grade, price;
        cin >> grade >> price;

        int extremumIndex = Item::findExtremum(inventory, n, false);
        inventory[extremumIndex].setName(name);
        inventory[extremumIndex].setGrade(grade);
        inventory[extremumIndex].setPrice(price);

        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                cout << "[ " << inventory[i].getName();
            }
            else if (i == n - 1)
            {
                cout << ", " << inventory[i].getName() << " ]" << endl;
            }
            else
            {
                cout << ", " << inventory[i].getName();
            }
        }
    }

    delete[] inventory;

    return 0;
}