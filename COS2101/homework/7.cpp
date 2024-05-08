#include <iostream>
#include <string>

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

void input1(string &text)
{
    cout << endl;
    cout << "ป้อนข้อความ: ";
    getline(cin, text);
}

void process1(string &text, int &a, int &e, int &i, int &o, int &u, int &other)
{
    find_aeiou(text, a, e, i, o, u, other);
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

void one()
{
    string text;
    int a = 0, e = 0, i = 0, o = 0, u = 0, other = 0;
    input1(text);
    process1(text, a, e, i, o, u, other);
    display1(a, e, i, o, u, other);
}

// 2

void CharReplaceText(string &text, char key, string replace)
{
    for (int i = 0; i < text.length(); i++)
    {
        int index = text.at(i);
        int start_index;

        // to lower
        if (index >= 'A' && index <= 'Z')
        {
            key = text.find(key + 32);
        }

        start_index = text.find(key);

        if (start_index != -1)
        {
            text.replace(start_index, 1, replace);
        }
    }
}

string lower(string text)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        char digit = text.at(i);
        if (digit >= 'A' && digit <= 'Z')
        {
            result += digit + 32;
        }
        else
        {
            result += digit;
        }
    }
    return result;
}

void StringReplaceText(string &text, string &key, string &replace)
{
    string text_lower = lower(text);
    while (text_lower.find(lower(key)) != -1)
    {
        text.replace(text_lower.find(lower(key)), key.length(), replace);
        text_lower = lower(text);
    }
}

void input2(string &text, string &find, string &replace)
{
    cout << "ป้อนข้อความ: ";
    getline(cin, text);

    cout << "ข้อความที่จะค้นหา: ";
    getline(cin, find);

    cout << "ข้อความที่จะแทนที่: ";
    getline(cin, replace);
}

void process2(string &text, string &find, string &replace)
{
    StringReplaceText(text, find, replace);
}

void display2(string &text)
{
    cout << text << endl;
}

void two()
{
    string text, find, replace;
    input2(text, find, replace);
    process2(text, find, replace);
    display2(text);
}

// 3

void game(string &key, string &guess, int &correct, int &right_position)
{
    for (int i = 0; i < key.length(); i++)
    {
        if (key.at(i) == guess.at(i))
        {
            right_position++;
        }
        for (int j = 0; j < guess.length(); j++)
        {
            if (key.at(i) == guess.at(j))
            {
                correct++;
            }
        }
    }
}

void intput3(string &guess, int &key_length)
{
    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
    } while (guess.length() > key_length || guess.length() < key_length);
}

void process3(string &key, string &guess, int &correct, int &right_position)
{
    game(key, guess, correct, right_position);
}

void display3(int &correct, int &right_position)
{
    cout << "Correct: " << correct << endl;
    cout << "Right position: " << right_position << endl;
}

void three()
{
    string key = "12345";
    int key_length = key.length();
    string guess;
    int correct = 0, right_position = 0;
    while (true)
    {

        // process
        intput3(guess, key_length);
        process3(key, guess, correct, right_position);
        display3(correct, right_position);

        // input
        cout << endl;
        int con;
        cout << "0 to exit, 1 to continue: ";
        cin >> con;
        if (con == 0)
        {
            break;
        }

        // reset
        cin.ignore();
        cin.clear();
        correct = 0;
        right_position = 0;
    }
}

// run
int select()
{
    int n;
    do
    {
        cout << "Enter a number: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Count vowel" << endl;
        cout << "2. Replace character" << endl;
        cout << "3. Guess number" << endl;
        cout << "Enter a choice: ";
        cin >> n;
        cout << endl;
    } while (n < 0 || n > 3);
    return n;
}

int main()
{
    one();
    two();
    three();

    // do
    // {
    //     n = select();

    //     cin.clear();
    //     cin.ignore();

    //     switch (n)
    //     {
    //     case 1:
    //         one();
    //         break;
    //     case 2:
    //         two();
    //         break;
    //     case 3:
    //         three();
    //         break;
    //     defaut:
    //         break;
    //     }
    //     cout << endl;

    // } while (n != 0);
    return 0;
}