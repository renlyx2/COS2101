#include <iostream>

using namespace std;

// 1

void input1(string text[], int &count)
{
    do
    {
        cout << "ป้อนข้อความรอบที่ " << count + 1 << ": ";
        cin >> text[count++];
    } while (text[count - 1] != "###");
}

bool is_palindrome(string text)
{
    int len = text.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (text[i] != text[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool is_palindrome_recursive(string text, int start = 0)
{
    int len = text.length();
    if (start < len / 2)
    {
        if (text[start] != text[len - (start + 1)])
        {
            return false;
        }
        return is_palindrome_recursive(text, start + 1);
    }
    return true;
}

void display1(const string text[], int &count)
{
    // string truefalse[2] = {"ไม่เป็น", "เป็น"};
    for (int i = 0; i < count; i++)
    {
        if (text[i] == "###")
        {
            break;
        }
        cout << text[i] << " " << (is_palindrome(text[i]) ? "เป็น" : "ไม่เป็น") << " palindrome" << endl;
        // cout << text[i] << " " << (is_palindrome_recursive(text[i]) ? "เป็น" : "ไม่เป็น")<< " palindrome" << endl;
    }
}

void one()
{
    // declare vars
    int count = 0;
    string text[50] = {""};

    // input
    input1(text, count);

    // display
    display1(text, count);
}

// 2

void input2(int &dec)
{
    do
    {
        cout << "ป้อนเลขฐาน 10 : ";
        cin >> dec;
    } while (dec < 0);
}

void display2(int &dec, string &bin, string &oct, string &hex)
{
    cout << "Binary = " << bin << endl;
    cout << "Octa = " << oct << endl;
    cout << "Hex = " << hex << endl;
}

string dec2any(int dec, const int base)
{
    char base_digit[16] = {'0', '1', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (dec == 0)
    {
        return "";
    }
    int rem = dec /= base;
    return base_digit[dec % base] + dec2any(rem, base);
}

void two()
{
    int dec;
    string bin;
    string oct;
    string hex;

    // input dec
    input2(dec);

    // process
    bin = dec2any(dec, 2);
    oct = dec2any(dec, 8);
    hex = dec2any(dec, 16);

    // display
    display2(dec, bin, oct, hex);
}

// main

int main()
{
    one();
    two();
    return 0;
}