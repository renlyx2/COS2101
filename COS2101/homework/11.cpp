#include <iostream>

using namespace std;

struct Book
{
    string id;
    string name;
    int type;
    int price;
};

void input(Book item[], int &size, int count[])
{
    string id;
    string name;
    int type;

    // รับข้อมูลหนังสือเล่มแรก
    cout << "ป้อนหลังสือเล่มที่: " << size + 1 << endl;
    cout << "id: ";
    cin >> id;

    // ตรวจสอบว่า id เป็น ### หรือไม่
    while (id != "###")
    {

        // ชื่อหนังสือ
        cout << "ชื่อหนังสือ: ";
        cin >> name;

        // ประเภทหนังสือ
        do
        {
            cout << "ประเภทหนังสือ 1.คอมพิวเตอร์ 2.คณิตศาสตร์ 3.สถิติ: ";
            cin >> type;
            if (type < 1 || type > 3)
            {
                cout << "ประเภทหนังสือไม่ถูกต้อง" << endl;
            }
        } while (type < 1 || type > 3);

        count[type - 1]++;

        // บันทึกข้อมูลหนังสือ
        item[size].id = id;
        item[size].name = name;
        item[size].type = type;

        // ราคาหนังสือ
        do
        {
            cout << "ราคาหนังสือ: ";
            cin >> item[size].price;
            if (item[size].price < 0)
            {
                cout << "ราคาหนังสือไม่ถูกต้อง" << endl;
            }
        } while (item[size].price < 0);

        cout << "____________________________________" << endl;
        cout << endl;

        // รับข้อมูลหนังสือเล่มถัดไป
        size++;
        cout << "ป้อนหลังสือเล่มที่: " << size + 1 << endl;
        cout << "id: ";
        cin >> id;
    }
}

void display(const Book item[], const int &size, const int type[])
{
    int total[3] = {0};

    // output
    cout << "รายการหนังสือทั้งหมด" << endl;

    cout << "1. คอมพิวเตอร์" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 1)
        {
            cout << ' ' << item[i].id << ' ' << item[i].name << ' ' << item[i].price << endl;
            total[0] += item[i].price;
        }
    }
    cout << "   ___________" << endl;
    cout << "   ราคารวม " << total[0] << " บาท" << endl;
    cout << endl;

    cout << "2. คณิตศาสตร์" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 2)
        {
            cout << ' ' << item[i].id << ' ' << item[i].name << ' ' << item[i].price << endl;
            total[1] += item[i].price;
        }
    }
    cout << "   ___________" << endl;
    cout << "ราคารวม " << total[1] << " บาท" << endl;
    cout << endl;

    cout << "3. สถิติ" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 3)
        {
            cout << ' ' << item[i].id << ' ' << item[i].name << ' ' << item[i].price << endl;
            total[2] += item[i].price;
        }
    }
    cout << "   ___________" << endl;
    cout << "ราคารวม: " << total[2] << " บาท" << endl;
    cout << endl;

    cout << "ราคาทั้งหมด: " << total[0] + total[1] + total[2] << " บาท" << endl;

    cout << "หนังสือทั้งหมด: " << size << " เล่ม" << endl;
    cout << "คอมพิวเตอร์: " << type[0] << " เล่ม" << endl;
    cout << "คณิตศาสตร์: " << type[1] << " เล่ม" << endl;
    cout << "สถิติ: " << type[2] << " เล่ม" << endl;
}

int main()
{
    Book item[100];
    int type_count[3] = {0};
    int size = 0;
    input(item, size, type_count);
    display(item, size, type_count);
    return 0;
}
