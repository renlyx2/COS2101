#include <iostream>
#include <string>
#include <limits>

using namespace std;

int handleInt(int value, string message = "Enter a number: ")
{
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer
            // ignores rest of the line
            // after first error occurs

            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
            cin >> value;
        }
        if (!cin.fail())
            break;
    }
    return value;
}

// 1. dec to hex

// string findHexArray(int n)
// {
//     string h = "";
//     string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
//     while (n > 0)
//     {
//         int temp = n % 16;
//         h = hex[temp] + h;
//         n = n / 16;
//     }
//     return h;
// }

// string findHexChar(int n)
// {
//     int x;
//     string h = "";
//     while (n > 0)
//     {
//         int x = n % 16;
//         if (x >= 0 && x <= 9)
//         {
//             h = to_string(x) + h;
//         }
//         else
//         {
//             h = char(x + 55) + h;
//         }
//         n = n / 16;
//     }
//     return h;
// }

string findHexSwitch(int n)
{
    int x;
    string h = "";
    while (n > 0)
    {
        int x = n % 16;
        if (x >= 0 && x <= 9)
        {
            h = to_string(x) + h;
        }
        else
        {
            switch (x)
            {
            case 10:
                h = "A" + h;
                break;
            case 11:
                h = "B" + h;
                break;
            case 12:
                h = "C" + h;
                break;
            case 13:
                h = "D" + h;
                break;
            case 14:
                h = "E" + h;
                break;
            case 15:
                h = "F" + h;
                break;
            }
        }
        n = n / 16;
    }
    return h;
}

void input1(int &n)
{
    do
    {
        cout << "Enter a number: ";
        cin >> n;
        n = handleInt(n);
    } while (n < 0);
}

void process1(int &n, string &h)
{
    h = findHexSwitch(n);
}

void show1(string &h)
{
    cout << "Hexadecimal: " << h << endl;
}

void one()
{
    int n;
    string h;
    input1(n);
    process1(n, h);
    show1(h);
}

// 2

float f(int &n)
{
    float i = 1.0, sum = 0.0;
    while (i <= n)
    {
        sum += i / (i + 1.0);
        i++;
    }
    return sum;
}

void input2(int &n)
{
    do
    {
        cout << "Enter a number: ";
        cin >> n;
        n = handleInt(n);
    } while (n < 0);
}

void process2(int &n, float &sum)
{
    sum = f(n);
}

void show2(float &sum)
{
    cout << "ผลลัพท์ " << sum << endl;
}

void two()
{
    int n;
    float sum;
    input2(n);
    process2(n, sum);
    show2(sum);
}

// 3

void input3(int &n, int &i, int except = 0)
{
    do
    {
        cout << "ป้อนตัวเลขลำดับที่ " << i << " : ";
        cin >> n;
        n = handleInt(n, "ป้อนตัวเลขลำดับที่ " + to_string(i) + " :");
    } while (n < 0 && n != except);
}

void FindEvenOdd1(int &sumEven, int &sumOdd, int &numEven, int &numOdd)
{
    int i = 1, temp;
    while (i <= 10)
    {

        input3(temp, i);

        if (temp % 2 == 0)
        {
            sumEven += temp;
            numEven++;
        }
        else
        {
            sumOdd += temp;
            numOdd++;
        }
        i++;
    }
}

void FindEvenOdd2(int &sumEven, int &sumOdd, int &numEven, int &numOdd)
{
    int i = 1, temp;
    while (true)
    {

        input3(temp, i, -999);

        if (temp == (-999))
        {
            break;
        }

        if (temp % 2 == 0)
        {
            sumEven += temp;
            numEven++;
        }
        else
        {
            sumOdd += temp;
            numOdd++;
        }
        i++;
    }
}

void show3(int &sumEven, int &sumOdd, int &numEven, int &numOdd)
{
    cout << "ผลรวมของจำนวนเลขคู่ = " << sumEven << endl;
    cout << "ผลรวมของจำนวนเลขคี่ = " << sumOdd << endl;
    cout << "จำนวนเลขคู่ = " << numEven << endl;
    cout << "จำนวนเลขคี่ = " << numOdd << endl;
}

int select3()
{
    int slt;
    do
    {
        cout << "1. ป้อนจำนวนเลข 10 จำนวน" << endl;
        cout << "2. ป้อนจำนวนเลขไม่แน่นอน และ ป้อน -999 เพื่อหยุด" << endl;
        cout << "เลือก : ";
        cin >> slt;
        slt = handleInt(slt, "เลือก : ");
    } while (slt != 1 && slt != 2);
    return slt;
}

void three()
{
    int n, sumEven = 0, sumOdd = 0, numEven = 0, numOdd = 0;

    int slt = select3();
    if (slt == 1)
    {
        FindEvenOdd1(sumEven, sumOdd, numEven, numOdd);
    }
    else if (slt == 2)
    {
        FindEvenOdd2(sumEven, sumOdd, numEven, numOdd);
    }
    show3(sumEven, sumOdd, numEven, numOdd);
}

// select

int select()
{
    int slt;
    do
    {
        cout << "0. ออกจากโปรแกรม" << endl;
        cout << "1. แปลงเลขฐาน 10 เป็นฐาน 16" << endl;
        cout << "2. คำนวณผลรวมของ 1/1 + 1/2 + 1/3 + ... + 1/n" << endl;
        cout << "3. คำนวณผลรวมของจำนวนเลขคู่ และ จำนวนเลขคี่" << endl;
        cout << "เลือก : ";
        cin >> slt;
        slt = handleInt(slt, "เลือก : ");
    } while (slt < 0 || slt > 3);
    return slt;
}

void _clear()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}

int main()
{
    int slt;
    do
    {
        slt = select();
        switch (slt)
        {
        case 1:
            _clear();
            one();
            break;
        case 2:
            _clear();
            two();
            break;
        case 3:
            _clear();
            three();
            break;
        }
        cout << endl;
    } while (slt != 0);
    return 0;
}
