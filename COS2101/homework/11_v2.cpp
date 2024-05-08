#include <iostream>
#include <string>
// #include <iomanip>

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
    item.name = "ไม่มีสินค้า";
    item.price = 0;
    item.stock = 0;
    return item;
}

void init(Product item[], int size)
{
    // ให้ข้อมูลเริ่มต้น
    item[0].id = 5;
    item[0].name = "สมุดเขียน";
    item[0].price = 10.0;
    item[0].stock = 3;

    item[1].id = 3;
    item[1].name = "ปากกา";
    item[1].price = 20.0;
    item[1].stock = 2;

    item[2].id = 4;
    item[2].name = "ยางลบ";
    item[2].price = 5.0;
    item[2].stock = 4;

    item[3].id = 2;
    item[3].name = "ดินสอ";
    item[3].price = 5.0;
    item[3].stock = 3;

    item[4].id = 6;
    item[4].name = "ปากกาสี";
    item[4].price = 15.0;
    item[4].stock = 1;

    item[5].id = 1;
    item[5].name = "สมุดวาดภาพ";
    item[5].price = 10.0;
    item[5].stock = 2;
}

Product bin_search(const Product item[], int first, int last, int key)
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
    else if ((key) < item[mid].id)
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
    cout << "สินค้าที่มีในร้าน" << endl;
    cout << "----------------------------------" << endl;
    cout << "รหัส ชื่อสินค้า ราคา จำนวนคงเหลือ" << endl;

    for (int i = 0; i < 6; i++)
    {
        if (item[i].stock > 0)
        {
            cout << item[i].id << ' ' << item[i].name << ' ' << item[i].price << ' ' << item[i].stock << endl;
        }
    }
    cout << endl;
}

void result(Product item[], int item_is_buy[], int total)
{
    cout << endl;
    cout << "สินค้าที่ซื้อ" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (item_is_buy[i] > 0)
        {
            cout << item[i].name << " " << item_is_buy[i] << " ชิ้น";
            cout << " (" << item[i].price << " บาท/ชิ้น)" << endl;
        }
    }
    cout << endl;
    cout << "ราคาสุทธิ: " << total << " บาท" << endl;
    cout << endl;
}

int main()
{
    int size = 6, total = 0;
    Product item[size];
    init(item, size);

    sort_item(item, size);
    display_item(item);

    int item_count[6] = {0};

    string find = "";

    while (true)
    {

        string key = "";

        cout << "ป้อนรหัสสินค้าที่จะซื้อ (เช่น 1 1 2) : ";

        getline(cin, find);
        find += ' ';

        for (int i = 0; i < find.length(); i++)
        {
            if (find[i] != ' ')
            {
                key += find[i];
            }
            else
            {
                int key_int = stoi(key);
                if (key_int > 0)
                {
                    Product find_item = bin_search(item, 0, 6, key_int);
                    if (find_item.id != -1 && find_item.stock > 0)
                    {
                        item_count[find_item.id - 1]++;
                        total += find_item.price;
                        item[find_item.id - 1].stock--;
                    }
                }
                key = "";
            }
        }

        result(item, item_count, total);

        string is_continue;
        cout << "ต้องการซื้อสินค้าต่อ ให้พิมพ์ 1 " << endl;
        cout << "พิมพ์อื่นๆ ชำระเงินและออกจากโปรแกรม" << endl;
        cout << "ป้อน : ";
        getline(cin, is_continue);

        if (is_continue == "1")
        {
            find = "";
            display_item(item);
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}