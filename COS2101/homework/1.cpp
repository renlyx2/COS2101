#include <iostream>
#define PI 3.14159f

using namespace std;

// 1.หาพื้นที่วงกลมและความยาวเส้นรอบวง

float triangleArea(float radius)
{
	return PI * (radius * radius);
}

float circumference(float radius)
{
	return 2 * PI * radius;
}

int triangle()
{
	float radius;

	cout << "ป้อนรัศมีของวงกลม : ";
	cin >> radius;

	cout << "พื้นที่ของวงกลม : " << triangleArea(radius) << endl;
	cout << "เส้นรอบวงของวงกลม : " << circumference(radius) << endl;
	cout << endl;
	return 0;
}

// 2.ไปแลกแบงค์ใหญ่ 1000 500 100 50 20 จากเหรียญบาทให้ได้จำนวนน้อยที่สุด

int coinExchange()
{
	int money;
	int moneyTypes[5] = {1000, 500, 100, 50, 20};

	cout << "ป้อนจำนวนเงิน: ";
	cin >> money;

	// for (int i = 0; i < 5; i++) {
	// 	int count = money / moneyTypes[i];
	// 	money = money % moneyTypes[i];
	// 	cout << "จำนวนเงิน " << moneyTypes[i] << " บาท จำนวน " << count << " ใบ" << endl;
	// }

	cout << endl;
	return 0;
}

// 3.จงหาส่วนลดของการซื้อสิ้นค้าและเงินจ่ายสุทธิ โดย ส่วนลด 5% ของซื้อสินค้า

int buyProduct()
{
	double price;

	// input
	cout << "ป้อนราคาสินค้า : ";
	cin >> price;

	// output
	cout << "ส่วนลด : " << price * 0.05 << endl;
	cout << "เงินจ่ายสุทธิ : " << price - (price * 0.05) << endl;
	cout << endl;
	return 0;
}

int main()
{
	int select;
	cout << "1.หาพื้นที่วงกลมและความยาวเส้นรอบวง" << endl;
	cout << "2.ไปแลกแบงค์ใหญ่ 1000 500 100 50 20 จากเหรียญบาทให้ได้จำนวนน้อยที่สุด" << endl;
	cout << "3.จงหาส่วนลดของการซื้อสิ้นค้าและเงินจ่ายสุทธิ โดย ส่วนลด 5% ของซื้อสินค้า" << endl;

	do
	{
		cout << "เลือกโปรแกรมที่ต้องการทำ : " << endl;
		cin >> select;
	} while (select < 1 || select > 3);

	switch (select)
	{
	case 1:
		triangle();
		break;
	case 2:
		coinExchange();
		break;
	case 3:
		buyProduct();
		break;
	}

	return 0;
}