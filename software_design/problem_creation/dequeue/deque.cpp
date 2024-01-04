#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
    string *deque;
    int begin, end;

public:
    Deque(int n)
    {
        deque = new string[n];
        begin = -1;
        end = -1;
    }

    void push_front(string s);
    void push_back(string s);
    void pop_front();
    void pop_back();
    void size();
    bool empty();
    void front();
    void back();

    ~Deque()
    {
        delete[] deque;
    }
};

void Deque::push_front(string s)
{
    if (empty())
    {
        begin = 0;
        end = 0;
        deque[begin] = s;
    }
    else
    {
        for (int i = end; i >= begin; i--)
        {
            deque[i + 1] = deque[i];
        }
        deque[begin] = s;
        end++;
    }
}

void Deque::push_back(string s)
{
    if (empty())
    {
        begin = 0;
        end = 0;
        deque[begin] = s;
    }
    else
    {
        end++;
        deque[end] = s;
    }
}

void Deque::pop_front()
{
    if (empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << deque[begin] << endl;
        deque[begin] = "\0";
        begin++;
    }
}

void Deque::pop_back()
{
    if (empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << deque[end] << endl;
        deque[end] = "\0";
        end--;
    }
}

void Deque::size()
{
    if (empty())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << end - begin + 1 << endl;
    }
}

bool Deque::empty()
{
    if (begin == -1 || begin > end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Deque::front()
{
    if (empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << deque[begin] << endl;
    }
}

void Deque::back()
{
    if (empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << deque[end] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    Deque d(n);

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "q")
        {
            break;
        }

        if (cmd == "push_front")
        {
            string s;
            cin >> s;

            d.push_front(s);
        }

        else if (cmd == "push_back")
        {
            string s;
            cin >> s;

            d.push_back(s);
        }

        else if (cmd == "pop_front")
        {
            d.pop_front();
        }

        else if (cmd == "pop_back")
        {
            d.pop_back();
        }

        else if (cmd == "size")
        {
            d.size();
        }

        else if (cmd == "empty")
        {
            cout << d.empty() << endl;
        }

        else if (cmd == "front")
        {
            d.front();
        }

        else if (cmd == "back")
        {
            d.back();
        }
    }

    return 0;
}