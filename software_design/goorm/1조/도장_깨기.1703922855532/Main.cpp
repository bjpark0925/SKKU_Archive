#include <iostream>
#include <string>
using namespace std;

class Fighter
{
private:
    string name;                  // 이름
    int *gameRecord = new int[2]; // 전적. gameRecord[0]이 승, gameRecord[1]이 패
    int performance;              // 경기력
public:
    Fighter()
    {
        name = "주인공";
        gameRecord[0] = 0;
        gameRecord[1] = 0;
        performance = 5;
    }
    Fighter(string _name, int c1, int c2, int perform)
    {
        name = _name;
        gameRecord[0] = c1;
        gameRecord[1] = c2;
        performance = perform;
    }
    // 디폴트 복사 생성자
    Fighter(const Fighter &c)
    {
        name = c.name;
        gameRecord[0] = c.gameRecord[0];
        gameRecord[1] = c.gameRecord[1];
        performance = c.performance;
    }
    ~Fighter()
    {
        delete[] gameRecord;
    }
    void setInfo(string _name, int g1, int g2, int perform)
    {
        name = _name;
        gameRecord[0] = g1;
        gameRecord[1] = g2;
        performance = perform;
    }
    int getSum()
    {
        return gameRecord[0] + gameRecord[1];
    }
    int getWin()
    {
        return gameRecord[0];
    }
    int getLose()
    {
        return gameRecord[1];
    }
    int getPerform()
    {
        return performance;
    }
    void setRecord(int num1, int num2)
    {
        gameRecord[0] += num1;
        gameRecord[1] += num2;
    }
    void setPerform(int num)
    {
        performance += num;
    }
};

// Fighter 객체 두 개를 받아 경기 결과를 예측하는 함수. 실제 객체 정보가 바뀌지 않는다.
// bool 형 반환값으로 승자를 구분한다.
bool expect(Fighter c, Fighter p)
{
    if (c.getPerform() > p.getPerform())
    {
        return true;
    }
    else if (c.getPerform() == p.getPerform())
    {
        if (c.getSum() > p.getSum())
        {
            return true;
        }
        else if (c.getSum() == p.getSum())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// Fighter 객체 두 개를 받아 경기를 치루는 함수. 실제 객체 정보가 바뀐다.
// bool 형 반환값으로 승자를 구분한다.
bool challenge(Fighter &c, Fighter &p)
{
    if (expect(c, p))
    {
        c.setPerform(p.getPerform());
        c.setRecord(1, 0);
        p.setRecord(0, 1);
        return true;
    }
    else
    {
        p.setPerform(c.getPerform());
        p.setRecord(1, 0);
        c.setRecord(0, 1);
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    Fighter* player=new Fighter[n];
    for (int i = 0; i < n; i++)
    {
        string iname;
        int g1, g2, iperform;
        cin >> iname;
        cin >> g1;
        cin >> g2;
        cin >> iperform;
        player[i].setInfo(iname, g1, g2, iperform);
    }

    string cname;
    int c1, c2, cperform;
    cin >> cname;
    cin >> c1;
    cin >> c2;
    cin >> cperform;
    Fighter champion(cname, c1, c2, cperform);

    Fighter character;
    bool is_title = true;
    int match_index = -1;
    int* matchArray = new int[n];
    int matchArray_pos = 0;
    while (character.getPerform() < champion.getPerform())
    {
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            for (int j = 0; j < matchArray_pos; j++)
            {
                if (i == matchArray[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                continue;
            }

            if (match_index == -1)
            {
                if (player[i].getPerform() <= character.getPerform())
                {
                    if (expect(character, player[i]))
                    {
                        match_index = i;
                    }
                }
            }
            else
            {
                if (((player[match_index].getPerform()<player[i].getPerform()))&&(player[i].getPerform()<=character.getPerform()))
                {
                    if (expect(character, player[i]))
                    {
                        match_index = i;
                    }
                }
            }
            
        }
        //cout<<"match_index: "<<match_index<<endl;
        if (match_index == -1) // 더 이상 매칭 상대가 없음
        {
            if (matchArray_pos<n) // 다 못 싸움
            {
                cout << "타이틀전 성사 실패" << endl;
                is_title = false;
            }
            break;
        }
        if (challenge(character, player[match_index]))
        {
            matchArray[matchArray_pos] = match_index;
            matchArray_pos++;
        }
        match_index = -1;
        /*
        cout<<"character perform: "<<character.getPerform()<<endl;
        cout<<"character win: "<<character.getWin()<<endl;
        cout<<"character lose: "<<character.getLose()<<endl;
        */
    }

    //타이틀전
    if (is_title)
    {
        cout << character.getWin() << "승 ";
        if (character.getLose() == 0)
        {
            cout << "무";
        }
        else
        {
            cout << character.getLose();
        }
        cout << "패로 타이틀전 성사" << endl;
        
        if (challenge(character, champion))
        {
            cout << character.getWin() << "승 ";
            if (character.getLose() == 0)
            {
                cout << "무";
            }
            else
            {
                cout << character.getLose();
            }
            cout << "패로 챔피언 등극!" << endl;
        }
        else
        {
            cout << character.getWin() << "승 ";
            if (character.getLose() == 0)
            {
                cout << "무";
            }
            else
            {
                cout << character.getLose();
            }
            cout << "패로 챔피언 도전 실패" << endl;
        }
    }

    delete [] player;
    delete [] matchArray;

    return 0;
}