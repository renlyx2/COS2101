#include <iostream>
#include <cmath>

using namespace std;

// รอบที่ 6 โจทย์ 1

void input1(int &n)
{
    do
    {
        cout << "Enter a number: ";
        cin >> n;
    } while (n < 1);
}

void print1(int &n)
{
    int count = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            count++;
            cout << count << " ";
        }
        cout << endl;
    }
}

void one()
{
    int n;
    input1(n);
    print1(n);
}

// รอบที่ 6 โจทย์ 2

long factorial(int n)
{
    long sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}

float permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

float combination(int n, int r)
{
    return factorial(n) / (factorial(n - r) * (factorial(r)));
}

void input2(int &n, int &r)
{
    cout << "Enter n: ";
    cin >> n;
    do
    {
        cout << "Enter r: ";
        cin >> r;
        if (r > n)
        {
            cout << "r must be less than or equal to n" << endl;
        }
    } while (r > n);
}

void process2(int n, int r, float &comb, float &perm)
{
    perm = permutation(n, r);
    comb = combination(n, r);
}

void output2(float comb, float perm)
{
    cout << "The combination is: " << comb << endl;
    cout << "The permutation is: " << perm << endl;
}

void two()
{
    int n, r;
    float comb, perm;
    input2(n, r);
    process2(n, r, comb, perm);
    output2(comb, perm);
}

// รอบที่ 6 โจทย์ 3

int bin2dec(long n)
{
    int i = 0, dec = 0, digit;
    while (n != 0)
    {
        digit = n % 10;
        dec += digit * pow(2, i);
        n /= 10;
        i++;
    }
    return dec;
}

bool handle(long value)
{
    while (value != 0)
    {
        if ((value % 10) > 1)
        {
            return false;
        }
        value /= 10;
    }
    return true;
}

void input3(long &bin)
{
    do
    {
        cout << "Enter a binary number: ";
        cin >> bin;
        if (handle(bin))
        {
            if (bin > 0)
            {
                break;
            }
        }
    } while (true);
}

void process3(long n, int &dec)
{
    dec = bin2dec(n);
}

void output3(long dec)
{
    cout << "The decimal equivalent is: " << dec << endl;
}

void three()
{
    long bin;
    int dec = 0;
    input3(bin);
    process3(bin, dec);
    output3(dec);
}

// run

int select()
{
    int n;
    do
    {
        cout << "Enter a number: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Number Triangle" << endl;
        cout << "2. Permutation and Combination" << endl;
        cout << "3. Binary to Decimal" << endl;
        cout << "Enter a choice: ";
        cin >> n;
        cout << endl;
    } while (n < 0 || n > 3);
    return n;
}

void _clear()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

int main()
{
    int n;
    do
    {
        n = select();
        switch (n)
        {
        case 1:
            one();
            break;
        case 2:
            two();
            break;
        case 3:
            three();
            break;
        defaut:
            break;
        }
        cout << endl;
    } while (n != 0);
    return 0;
}