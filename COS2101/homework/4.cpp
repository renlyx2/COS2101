#include <iostream>

using namespace std;

// ข้อ 1

int checkNumber(int &number)
{
    if (number > 0)
    {
        return 1;
    }
    else if (number < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void input1(int &number)
{
    cout << "ป้อนตัวเลข: ";
    cin >> number;
    cout << endl;
}

void output1(int &number)
{
    cout << "ผลลัพธ์: " << checkNumber(number) << endl;
}

void one()
{
    int number;
    input1(number);
    output1(number);
}

// ข้อ 2

int findWater(int unit)
{
    if (unit > 100)
    {
        return (unit - 100) * 30 + 300 + 600 + 1250;
    }
    if (unit >= 51 && unit <= 100)
    {
        return (unit - 50) * 25 + 300 + 600;
    }
    if (unit >= 21 && unit <= 50)
    {
        return 300 + (unit - 20) * 20;
    }
    else
    {
        return unit * 15;
    }
}

void input2(int &currentMeter, int &lastMeter)
{
    cout << "ป้อนเลขมิเตอร์เดือนที่แล้ว: ";
    cin >> lastMeter;
    cout << "ป้อนเลขมิเตอร์ปัจจุบัน: ";
    cin >> currentMeter;
    cout << endl;
}

void process2(int &currentMeter, int &lastMeter, int &unit, int &price)
{
    unit = currentMeter - lastMeter;
    price = findWater(unit);
}

void output2(int &unit, int &water)
{
    cout << "จำนวนน้ำที่ใช้: " << unit << " (ยูนิต)" << endl;
    cout << "ค่าน้ำ: " << water << " (บาท)" << endl;
}

void two()
{
    int currentMeter, lastMeter, unit, price = 0;
    input2(currentMeter, lastMeter);
    process2(currentMeter, lastMeter, unit, price);
    output2(unit, price);
}

// ข้อ 3

void input3(int &pd, int &pm, int &py, int &bd, int &bm, int &by)
{
    cout << "ป้อนวันปัจจุบัน: ";
    cin >> pd;
    cout << "ป้อนเดือนปัจจุบัน: ";
    cin >> pm;
    cout << "ป้อนปีปัจจุบัน(ค.ศ.): ";
    cin >> py;
    cout << "ป้อนวันเกิด: ";
    cin >> bd;
    cout << "ป้อนเดือนเกิด: ";
    cin >> bm;
    cout << "ป้อนปีเกิด(ค.ศ.): ";
    cin >> by;
    cout << endl;
}

void findAge(int &pd, int &pm, int &py, int &bd, int &bm, int &by, int &m, int &y)
{
    int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    y = py - by;

    if (pm < bm)
    {
        y--;
        m = 12 - (bm - pm);
    }
    else
    {
        m = pm - bm;
    }
}

void process3(int &pd, int &pm, int &py, int &bd, int &bm, int &by, int &m, int &y)
{
    findAge(pd, pm, py, bd, bm, by, m, y);
}

void output3(int &m, int &y)
{
    cout << "อายุ: " << y << " ปี " << m << " เดือน " << endl;
}

void three()
{
    int pd, pm, py, bd, bm, by, m, y;
    input3(pd, pm, py, bd, bm, by);
    process3(pd, pm, py, bd, bm, by, m, y);
    output3(m, y);
}

int main()
{
    one();
    two();
    three();
    return 0;
}