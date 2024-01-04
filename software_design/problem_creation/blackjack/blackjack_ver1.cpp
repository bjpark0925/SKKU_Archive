#include <iostream>
#include <string>
using namespace std;

#define MAXNUM 52

class DeckofCards // main 함수에서 DeckofCards deck[15]로 선언하고 사용. 덱에서 무늬별 카드 개수가 몇개인지 확인
{
private:
    int count; // 무늬별 카드 개수
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
        if (value > 13 || count >= 4)
        {
            int value;
            cout << "choose another value(1~13): ";
            cin >> value;
            deck[value].cardDistribute(deck, value);
        }
        else if (value == 1)
        {
            deck[11].cardDistribute(deck, 11);
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
    DeckofCards myCard[15];

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
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setMoney(int money)
    {
        this->money = money;
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
        {
            cout << this->name << " BURST..." << endl;
            return true;
        }
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
        else if (num == 11)
        {
            if (this->myCardPoint() > 10)
            {
                num = 1;
            }
        }
        myCard[num].addCount(1);
    }
    int myCardPoint() // card 점수를 보여준다.
    {
        int sum = 0;
        for (int i = 0; i < 15; i++)
        {
            sum += i * myCard[i].getCount();
        }
        return sum;
    }
    void initMyCard() // 카드 초기화
    {
        for (int i = 0; i < 15; i++)
        {
            myCard[i].addCount(-myCard[i].getCount());
        }
    }
};

int main()
{
    string name;
    int age, money;
    cout << "player name: ";
    cin >> name;
    cout << "player age: ";
    cin >> age;
    cout << "player money: ";
    cin >> money;

    Person player(name, age, money);
    cout << "===============================" << endl;
    cout << "check player information" << endl;
    cout << "player name: " << player.getName() << endl;
    cout << "player age: " << player.getAge() << endl;
    cout << "player money: " << player.getMoney() << endl;
    cout << "===============================" << endl;

    bool play = true;
    int playerWin = 0;
    int isBurst = 0;
    while (play)
    {
        string pinput;
        cout << "Do you want to play a game? (y/n): ";
        cin >> pinput;
        if (pinput == "n")
        {
            play = false;
            break;
        }
        else if (pinput != "y")
        {
            cout << "wrong input" << endl;
            continue;
        }

        // 배팅금액 입력
        int betting = 0;
        bool exceed = true;
        while (exceed)
        {
            cout << "bet your money: ";
            cin >> betting;
            if (betting > player.getMoney())
            {
                cout << "exceed your money" << endl;
                continue;
            }
            cout << "your remaining money: " << player.subMoney(betting) << endl;
            exceed = false;
        }

        // 카드 분배
        int dvalue;
        Person dealer;
        DeckofCards deck[15]; // 전체 카드 덱. 무늬별 카드 개수 4개 초과 시 분배 억제. 다른 숫자 카드로 분배 유도. deck[0]과 deck[1]은 사용하지 않는다.
        cout << "enter the card value(give to dealer)(1~13): ";
        cin >> dvalue;
        dvalue = deck[dvalue].cardDistribute(deck, dvalue);
        dealer.addCard(dvalue);

        int pvalue1, pvalue2;
        cout << "enter the two card values(give to player)(1~13): ";
        cin >> pvalue1;
        cin >> pvalue2;
        pvalue1 = deck[pvalue1].cardDistribute(deck, pvalue1);
        pvalue2 = deck[pvalue2].cardDistribute(deck, pvalue2);
        player.addCard(pvalue1);
        player.addCard(pvalue2);

        // 카드 합 확인
        cout << "dealer's card sum: " << dealer.myCardPoint() << endl;
        cout << "player's card sum: " << player.myCardPoint() << endl;
        if (player.isBurst()) // burst 여부 확인
        {
            playerWin = 0;
            isBurst = 1;
        }

        // player 카드 추가
        while (true)
        {
            if (isBurst)
            {
                break;
            }
            string ainput;
            cout << "Do you want to add the card? (y/n): ";
            cin >> ainput;
            if (ainput == "y")
            {
                int pvalue;
                cout << "enter the card value(give to player additionally)(1~13): ";
                cin >> pvalue;
                pvalue = deck[pvalue].cardDistribute(deck, pvalue);
                player.addCard(pvalue);
                // player add 후 카드 합 확인
                cout << "dealer's card sum: " << dealer.myCardPoint() << endl;
                cout << "player's card sum: " << player.myCardPoint() << endl;
                if (player.isBurst())
                {
                    playerWin = 0;
                    isBurst = 1;
                    break;
                }
            }
            else if (ainput == "n")
            {
                break;
            }
            else
            {
                cout << "wrong input" << endl;
                continue;
            }
        }

        // dealer 카드 추가
        while (true)
        {
            if (isBurst)
            {
                break;
            }
            int final_dvalue;
            cout << "enter the card value(give to dealer lastly): ";
            cin >> final_dvalue;
            final_dvalue = deck[final_dvalue].cardDistribute(deck, final_dvalue);
            dealer.addCard(final_dvalue);
            break;
        }

        // dealer add 후 카드 합 확인
        cout << "dealer's card sum: " << dealer.myCardPoint() << endl;
        cout << "player's card sum: " << player.myCardPoint() << endl;

        if (dealer.isBurst())
        {
            playerWin = 1;
            isBurst = 1;
        }
        // 승패 결정
        if (isBurst == 0)
        {
            if (dealer.myCardPoint() > player.myCardPoint())
            {
                playerWin = 0;
            }
            else if (dealer.myCardPoint() < player.myCardPoint())
            {
                playerWin = 1;
            }
            else // 무승부
            {
                playerWin = -1;
            }
        }

        // 배팅금액 계산
        if (playerWin == 1)
        {
            cout << "player win!" << endl;
            player.addMoney(betting * 2);
            cout << player.getMoney() << "(+" << betting << ")" << endl;
        }
        else if (playerWin == 0)
        {
            cout << "player lose..." << endl;
            cout << player.getMoney() << "(-" << betting << ")" << endl;
        }
        else
        {
            cout << "draw" << endl;
            player.addMoney(betting * 2);
            cout << player.getMoney() << "(+0)" << endl;
        }

        // 반복문 위해 초기화
        player.initMyCard();
        dealer.initMyCard();
        isBurst = 0;
    }

    // 프로그램 종료
    cout << "terminating player information" << endl;
    cout << "player name: " << player.getName() << endl;
    cout << "player age: " << player.getAge() << endl;
    cout << "player money: " << player.getMoney() << endl;

    return 0;
}