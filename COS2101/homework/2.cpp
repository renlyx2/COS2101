#include <iostream>
#include <cmath>

using namespace std;

// 1.จงแปลง หลา, ฟุต, นิ้ว เป็น นิ้วรวม

double ydftin(double yd, double ft, double in)
{
    return yd * 36 + ft * 12 + in;
}

void toinch()
{
    double yd, ft, in;
    cout << "ป้อนความยาวหลา : ";
    cin >> yd;
    ;
    cout << "ป้อนความยาวฟุต : ";
    cin >> ft;
    cout << "ป้อนความยาวนิ้ว : ";
    cin >> in;
    cout << "ความยาว : " << ydftin(yd, ft, in) << " นิ้ว" << endl;
}

// 2.จงสร้างฟังก์ชัน หาค่าของ y = y = -b +- sqrt(b^2 - 4ac) / 2a

double y(double a, double b, double c, bool is_negative = false)
{
    if (is_negative)
    {
        return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    else
    {
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    }
}

void quadratic()
{
    double a, b, c;
    cout << "ป้อนค่า a : ";
    cin >> a;
    cout << "ป้อนค่า b : ";
    cin >> b;
    cout << "ป้อนค่า c : ";
    cin >> c;
    cout << "y = " << y(a, b, c) << "," << y(a, b, c, true) << endl;
}

// 3.จงหาส่วนลดของการซื้อสินค้าและจำนวนจ่ายสุทธิ

double findDiscount(double price)
{
    return price * 0.1;
}

double findVat(double price)
{
    return (price - findDiscount(price)) * 0.07;
}

double findNet(double price)
{
    return (price - findDiscount(price)) + findVat(price);
}

void shoping()
{
    double price;
    cout << "ป้อนราคาสินค้า : ";
    cin >> price;
    cout << "ส่วนลด : " << findDiscount(price) << endl;
    cout << "จำนวนจ่ายสุทธิ : " << findNet(price) << endl;
}

void choices()
{
    cout << "1. แปลงหลา, ฟุต, นิ้ว เป็น นิ้วรวม" << endl;
    cout << "2. หาค่าของ y = y = -b +- sqrt(b^2 - 4ac) / 2a" << endl;
    cout << "3. หาส่วนลดของการซื้อสินค้าและจำนวนจ่ายสุทธิ" << endl;
}

void select(int &x)
{
    do
    {
        cout << "ป้อนตัวเลือกของคุณ : ";
        cin >> x;
        cout << endl;
    } while (x < 1 || x > 3);
}

bool conti()
{
    char c;
    cout << endl
         << "ต้องการทำต่อหรือไม่ (y/n) : ";
    cin >> c;
    cout << endl;
    return c == 'y';
}

// รันโปรแกรม

int main()
{
    int x = 0;
    bool is_continue = true;
    while (is_continue)
    {
        choices();
        select(x);
        switch (x)
        {
        case 1:
            toinch();
            break;
        case 2:
            quadratic();
            break;
        case 3:
            shoping();
            break;
        }
        is_continue = conti();
    }

    return 0;
}