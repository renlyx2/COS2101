#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void find_aeiou(string text, int &a, int &e, int &i, int &o, int &u, int &other)
{
    for (int n = 0; n < text.length(); n++)
    {
        char t = text.at(n);
        if (t == ' ')
        {
            continue;
        }
        if (t == 'A' || t == 'a')
        {
            a++;
        }
        else if (t == 'E' || t == 'e')
        {
            e++;
        }
        else if (t == 'I' || t == 'i')
        {
            i++;
        }
        else if (t == 'O' || t == 'o')
        {
            o++;
        }
        else if (t == 'U' || t == 'u')
        {
            u++;
        }
        else
        {
            other++;
        }
    }
}

void display1(int &a, int &e, int &i, int &o, int &u, int &other)
{
    cout << "A: " << a << endl;
    cout << "E: " << e << endl;
    cout << "I: " << i << endl;
    cout << "O: " << o << endl;
    cout << "U: " << u << endl;
    cout << "Other: " << other << endl;
}

void input1(string &text)
{
    cout << endl;
    cout << "ป้อนข้อความ: ";
    getline(cin, text);
}

void one()
{
    string text;
    int a = 0, e = 0, i = 0, o = 0, u = 0, other = 0;
    input1(text);
    find_aeiou(text, a, e, i, o, u, other);
    display1(a, e, i, o, u, other);
}