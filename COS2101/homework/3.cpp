#include <iostream>
#include <cmath>

using namespace std;

void input(int &a, int &b, int &c, int &d)
{
    cout << "ป้อน a: ";
    cin >> a;
    cout << "ป้อน b: ";
    cin >> b;
    cout << "ป้อน c: ";
    cin >> c;
    cout << "ป้อน d: ";
    cin >> d;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// output d c b a
void process(int &a, int &b, int &c, int &d)
{
    swap(a, d);
    swap(b, c);
    // if (a > b)
    // {
    //     swap(a, b);
    // }
    // if (a > c)
    // {
    //     swap(a, c);
    // }
    // if (a > d)
    // {
    //     swap(a, d);
    // }
    // if (b > c)
    // {
    //     swap(b, c);
    // }
    // if (b > d)
    // {
    //     swap(b, d);
    // }
    // if (c > d)
    // {
    //     swap(c, d);
    // }
}

void output(int &a, int &b, int &c, int &d)
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

void one()
{
    int a, b, c, d;
    input(a, b, c, d);
    process(a, b, c, d);
    output(a, b, c, d);
}

// ข้อ 2

void input2(int &s)
{
    cout << "ป้อนวินาที : ";
    cin >> s;
}

void process2(int &s, int &m, int &h)
{
    int temp = s;
    h = temp / 3600;
    m = (temp % 3600) / 60;
    s = (temp % 3600) % 60;
}

void output2(int &s, int &m, int &h)
{
    cout << "เวลาที่แปลงได้ : " << h << " ชั่วโมง " << m << " นาที " << s << " วินาที " << endl;
}

void two()
{
    int seconds, minutes, hours;
    input2(seconds);
    process2(seconds, minutes, hours);
    output2(seconds, minutes, hours);
}

// ข้อ 3

float findArea(float radius)
{
    return 3.14159f * pow(radius, 2);
}

float findLength(float radius)
{
    return 2 * 3.14159f * radius;
}

void input3(float &radius)
{
    cout << "ป้อนรัศมีของวงกลม : ";
    cin >> radius;
}

void process3(float &radius, float &area, float &length)
{
    area = findArea(radius);
    length = findLength(radius);
}

void output3(float &radius)
{
    cout << "พื้นที่ของวงกลม : " << findArea(radius) << endl;
    cout << "เส้นรอบวงของวงกลม : " << findLength(radius) << endl;
}

void three()
{
    float radius, area, length;
    input3(radius);
    process3(radius, area, length);
    output3(radius);
}

// ข้อ 4 ดอกเบี้ยทบต้นของเงินฝาก
// ป้อนเงินฝาก กับ อัตราดอกเบี้ย 1 ปี

float findInterest(float &money, float &rate)
{
    return money * rate / 100;
}

void findCompound(float money, float rate, float &final)
{
    final = money + findInterest(money, rate);
}

void input4(float &money, float &rate)
{
    cout << "ป้อนเงินฝาก : ";
    cin >> money;
    cout << "ป้อนอัตราดอกเบี้ย : ";
    cin >> rate;
    cout << endl;
}

void process4(float &money, float &rate, float &final)
{
    findCompound(money, rate, final);
}

void output4(float &money, float &rate, float &final)
{
    cout << "เงินต้น : " << money << endl;
    cout << "ดอกเบี้ยที่ได้รับ : " << findInterest(money, rate) << endl;
    cout << "เงินฝากรวมดอกเบี้ย : " << final << endl;
}

void four()
{
    float money, rate, final;
    input4(money, rate);
    process4(money, rate, final);
    output4(money, rate, final);
}

// run program

void choices()
{
    cout << "ข้อ 1 : สลับค่าของตัวแปร 4 ตัว" << endl;
    cout << "ข้อ 2 : วินาทีรวม แปลงเป็น ชั่วโมง นาที วินาที" << endl;
    cout << "ข้อ 3 : พื้นที่ และ เส้นรอบวง" << endl;
    cout << "ข้อ 4 : ดอกเบี้ยทบต้นของเงินฝากประจำ 1 ปี" << endl;
}

void select(int &x)
{
    do
    {
        cout << "ป้อนตัวเลือกของคุณ : ";
        cin >> x;
        cout << endl;
    } while (x < 1 || x > 4);
}

bool conti()
{
    int number;
    cout << endl
         << "ต้องการทำต่อหรือไม่ (1 = ต้องการ, 0 = ไม่ต้องการ) : ";
    cin >> number;
    cout << endl;
    return (number == 1);
}

int main()
{
    int choice;
    bool is_continue = true;

    while (is_continue)
    {
        choices();
        select(choice);
        switch (choice)
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
        case 4:
            four();
            break;
        }
        is_continue = conti();
    }
    return 0;
}