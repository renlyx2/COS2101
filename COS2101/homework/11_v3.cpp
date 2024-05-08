#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Product
{
    int id;
    string name;
    float price;
    int stock;
};

Product fake_item()
{
    Product item;
    item.id = -1;
    item.name = "none";
    item.price = 0;
    item.stock = 0;
    return item;
}

void init(Product item[])
{
    // ให้ข้อมูลเริ่มต้น
    item[0].id = 1001;
    item[0].name = "A";
    item[0].price = 2.50;
    item[0].stock = 10;

    item[1].id = 1002;
    item[1].name = "B";
    item[1].price = 3.50;
    item[1].stock = 20;

    item[2].id = 1003;
    item[2].name = "C";
    item[2].price = 4.50;
    item[2].stock = 30;

    item[3].id = 1004;
    item[3].name = "D";
    item[3].price = 5.50;
    item[3].stock = 40;

    item[4].id = 1005;
    item[4].name = "E";
    item[4].price = 6.50;
    item[4].stock = 50;
}

Product bin_search(const Product item[], int first, int last, const int key)
{
    int mid = (first + last) / 2;
    if (first > last)
    {
        return fake_item();
    }
    else if (key == item[mid].id)
    {
        return item[mid];
    }
    else if (key < item[mid].id)
    {
        return bin_search(item, first, mid - 1, key);
    }
    else
    {
        return bin_search(item, mid + 1, last, key);
    }
}

void sort_item(Product item[], int size)
{
    bool swapped = true;
    Product temp;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < (size - 1); i++)
        {
            if (item[i].id > item[i + 1].id)
            {
                temp = item[i];
                item[i] = item[i + 1];
                item[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void display_item(Product item[])
{
    cout << endl;
    cout << "สินค้าที่มีในร้าน" << endl;
    cout << "----------------------------------" << endl;
    cout << "id" << setw(10) << "name" << setw(10) << "price" << setw(10) << "stock" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (item[i].stock > 0)
        {
            cout << item[i].id << setw(10) << item[i].name << setw(10) << item[i].price << setw(10) << item[i].stock << endl;
        }
    }
    cout << "----------------------------------" << endl;
    cout << endl;
}

void result(Product item[], int item_is_buy[], const int &size, int total)
{
    cout << endl;
    cout << "สินค้าที่ซื้อ" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (item_is_buy[i] > size)
        {
            cout << item[i].name << " " << item_is_buy[i] << " ชิ้น";
            cout << " (" << item[i].price << " บาท/ชิ้น)" << endl;
        }
    }
    cout << endl;
    cout << "ราคาสุทธิ: " << total << " บาท" << endl;
    cout << endl;
}

void buy_product(Product item[], int item_count[], const int &size, int &total)
{
    int product_id;
    int product_quality = 0;
    Product product;

    do
    {
        cout << "ป้อนรหัสสินค้า : ";
        cin >> product_id;
        product = bin_search(item, 0, size, product_id);
        if (product.id == -1)
        {
            cout << "ไม่มีสินค้านี้ในร้าน" << endl;
        }
    } while (product.id == -1);

    do
    {
        cout << "ป้อนจำนวน : ";
        cin >> product_quality;
        if (product_quality > product.stock && product_quality > 0)
        {
            cout << "สินค้ามีจำนวนไม่เพียงพอ" << endl;
        }
    } while (product_quality > product.stock);

    // process
    item_count[product.id] += product_quality;
    total += product.price * product_quality;

    for (int i = 0; i < size; i++)
    {
        if (item[i].id == product_id)
        {
            item[i].stock -= product_quality;
        }
    }

    // item[product.id - 1].stock -= product_quality;
    cout << "ซื้อสินค้า " << product.name << " สำเร็จ, จำนวน " << product_quality << " ชิ้น, ราคา " << product.price * product_quality << " บาท" << endl;
    cout << endl;
}

int main()
{
    const int size = 5;
    int total = 0;
    int count[2000] = {0};
    Product item[size];
    char choice = ' ';
    float money;

    init(item);
    sort_item(item, size);

    do
    {
        display_item(item);
        buy_product(item, count, size, total);

        do
        {
            cout << "1. ซื้อสินค้าต่อ" << endl;
            cout << "2. เพื่อไปชำระเงิน " << endl;
            cout << "เลือกทำรายการต่อ: ";
            cin >> choice;
            if (choice != '1' && choice != '2')
            {
                cout << "กรุณาเลือกทำรายการใหม่" << endl;
            }
        } while (choice != '1' && choice != '2');

        cout << endl;

    } while (choice == '1');

    result(item, count, size, total);

    do
    {
        cout << "ชำระเงิน : ";
        cin >> money;
        if (money < total)
        {
            cout << "เงินที่คุณใส่มาไม่พอ กรุณาใส่เงินใหม่" << endl;
        }
    } while (money < total);

    if (money > total)
    {
        cout << "เงินทอน : " << money - total << " บาท" << endl;
    }

    cout << "ขอบคุณที่ใช้บริการ" << endl;

    return 0;
}