#include <iostream>
#include <string>
using namespace std;

class DeckofCards // main 함수에서 DeckofCards deck[14]로 선언하고 사용. 덱에서 종류별 카드 개수가 몇개인지 확인
{
private:
    int count; // 종류별 카드 개수
public:
    DeckofCards()
    {
        count = 0;
    }
    int getCount()
    {
        return count;
    }
    void addCount(int num)
    {
        count += num;
    }
    int cardDistribute(DeckofCards *deck, int value)
    {
        if (count >= 4)
        {
            int new_value;
            cout << "choose another value" << endl;
            cin >> new_value;
            return deck[new_value].cardDistribute(deck, new_value);
        }
        else
        {
            count++;
            return value;
        }
    }
};

class Person
{
private:
    string name;
    int age;
    int money;
    DeckofCards myCard[14];
public:
    Person()
    {
        name = "Dealer";
        age = 0;
        money = 0;
    }
    Person(string name, int age, int money)
    {
        this->name = name;
        this->age = age;
        this->money = money;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getMoney()
    {
        return money;
    }
    int subMoney(int money)
    {
        this->money -= money;
        return this->money;
    }
    int addMoney(int money)
    {
        this->money += money;
        return this->money;
    }
    bool isBurst() // 카드 합이 21 초과되어 burst된 경우 true return
    {
        if (this->myCardPoint() > 21)
            return true;
        else
            return false;
    }
    void addCard(int num) // card를 받는다.
    {
        if (num == 1)
        {
            if (this->myCardPoint() <= 10)
            {
                num = 11;
            }
        }
        myCard[num].addCount(1);
    }
    int myCardPoint() // card 점수를 보여준다.
    {
        int sum = 0;
        for (int i = 0; i < 14; i++)
        {
            sum += i * myCard[i].getCount();
        }
        return sum;
    }
};

int main()
{
    string name;
    int age, money;
    cin >> name;
    cin >> age;
    cin >> money;

    Person player(name, age, money);
    cout << player.getName() << endl;
    cout << player.getAge() << endl;
    cout << player.getMoney() << endl;

    // 게임 시작
    int playerWin = 0;
    int isBurst = 0;

    // 배팅금액 입력
    int betting = 0;
    cin >> betting;
    cout << player.subMoney(betting) << endl;

    // 카드 분배(딜러 2개, 플레이어 3개)
    int dvalue1, dvalue2;
    int pvalue1, pvalue2, pvalue3;
    Person dealer;
    DeckofCards deck[14]; // 전체 카드 덱. 종류별 카드 개수 4개 초과 시 분배 억제. 다른 숫자 카드로 분배 유도. deck[0]은 사용하지 않는다.
    cin >> dvalue1;
    cin >> dvalue2;
    dvalue1 = deck[dvalue1].cardDistribute(deck, dvalue1);
    dvalue2 = deck[dvalue2].cardDistribute(deck, dvalue2);
    dealer.addCard(dvalue1);
    dealer.addCard(dvalue2);

    cin >> pvalue1;
    cin >> pvalue2;
    cin >> pvalue3;
    pvalue1 = deck[pvalue1].cardDistribute(deck, pvalue1);
    pvalue2 = deck[pvalue2].cardDistribute(deck, pvalue2);
    pvalue3 = deck[pvalue3].cardDistribute(deck, pvalue3);
    player.addCard(pvalue1);
    player.addCard(pvalue2);
    player.addCard(pvalue3);

    // 최종 카드 합 확인
    cout << dealer.myCardPoint() << endl;
    cout << player.myCardPoint() << endl;

    if (player.isBurst())
    {
        isBurst = 1;
        if (dealer.isBurst())
            playerWin = -1; // 무승부
        else
            playerWin = 0; // 패배
    }
    else
    {
        if (dealer.isBurst())
        {
            isBurst = 1;
            playerWin = 1; // 승리
        }
    }

    // 승패 결정
    if (isBurst == 0)
    {
        if (dealer.myCardPoint() > player.myCardPoint())
            playerWin = 0;
        else if (dealer.myCardPoint() < player.myCardPoint())
            playerWin = 1;
        else // 무승부
            playerWin = -1;
    }

    // 배팅금액 계산
    if (playerWin == 1)
    {
        player.addMoney(betting * 2);
        cout << player.getMoney() << endl;
    }
    else if (playerWin == 0)
    {
        cout << player.getMoney() << endl;
    }
    else
    {
        player.addMoney(betting);
        cout << player.getMoney() << endl;
    }

    return 0;
}