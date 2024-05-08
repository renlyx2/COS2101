# ระเบียนข้อมูล record

คือกลุ่มข้อรายการข้อมูลที่สัมพันธ์กัน
เช่น \
bit 01 \
byte 10101010 แทน1ตัวอักษร \
field รายการข้อมูลเช่น ชื่อ นามสกุล อายุ \
ที่อยู่ อีเมล์ เบอร์โทรศัพท์ \
record ระเบียน \

ตย ระเบียน นศ ประกอบด้วยฟิลด์หลัก, ฟิลด์ชื่อ,อายุ, เกรดเฉลี่ย

```
student1:
    id=?  101  (string)
    name=? A (string)
    age=? 20 (int)
    grade=? 3.5 (float)

student2:
    id=?  102
    name=? B
    age=? 21
    grade=? 3.6

student3:
    id=?  ### // ลบข้อมูล
```

โปรแกรมเมอร์ ประกาศโครงสร้างระเบียน เพื่อเก็บข้อมูลเป็นกลุ่ม โดยกำหนดฟิลด์(รายการข้ฮมูล) และชนิดของข้อมูลเพื่อให้ ตัวแปรมา?รู้จัก

- record
  | id | name | age | grade |

1. ตั่งชิ้อโครงสร้างระเบียน (ไม่จองเนิ้อที่)
2. ประกาศให้คอมไฟเลอร์ทราบ รู้จัก ว่าระเบียนมีรายการข้อมูลอะไรบ้าง

- รูปแบบ

```cpp

struct ชื่อโครงสร้างใหม่
{
    type ชื่อฟิลด์1;
    type ชื่อฟิลด์2;
};
```

- ตัวอย่าง

```cpp
struct student
{
    string id;
    string name;
    int age;
    float grade;
};
```

- การใช้งาน

```cpp
// ประกาศตัวแปรชนิดระเบียน
student item1;
student item2;
// จองเนื้อที่ 1 ระเบียนว่าง ให้ item1 และ item2 ชี้ไปยังระเบียนนั้น
```

item1
| id | name | age | grade |

<!-- | --- | --- | --- | --- |
| 101 | A | 20 | 3.5 | -->

item2
| id | name | age | grade |

<!-- | --- | --- | --- | --- |
| 102 | B | 21 | 3.6 | -->

- การอ้างใช้

// ระเบียน.ฟิลด์ = ค่าที่ต้องการให้เก็บ
item1.id = "101";
item1.name = "A";
item1.age = 20;
item1.grade = 3.5;

student item[5]; // จองเนื้อที่ 5 ระเบียนว่าง ให้ item[0] ถึง item[4] ชี้ไปยังระเบียนนั้น

| 0       | 1       | 2       | 3       | 4       |
| ------- | ------- | ------- | ------- | ------- |
| item[0] | item[1] | item[2] | item[3] | item[4] |

// โดยแต่ละ ช่องของ item จะแบ่งเป็น 4 ฟิลด์ ดังนี้

| 0   | 1    | 2   | 3     | 4   |
| --- | ---- | --- | ----- | --- |
| id  | name | age | grade | id  |

// การอ้างใช้
item[0].id = "101";
item[0].name = "A";
item[0].age = 20;
item[0].grade = 3.5;

0 คือตัวชี้ ชี้ไปยังช่องที่ 0 ของ item

## array 2d

```cpp
student item[2][3];
```

| stundent | 0          | 1          | 2          |
| -------- | ---------- | ---------- | ---------- |
| 0        | item[0][0] | item[0][1] | item[0][2] |
| 1        | item[1][0] | item[1][1] | item[1][2] |

## Example 1 array

จงหา ภาษีที่ต้องจ่ายภาษีของพนักงงานจำนวน n คน

#### เงื่อนไขการคำนวณภาษีต่อปี

1. นำเงินเดือนของพนักงงานทุกดือนมาบวกันเป็นรายได้ทั่งปี
2. รายการลดหน่อย

- 2.1 หักค่าใช้จาายส่วนตัว 40% ของรายได้ทั่งปี แต่ไม่เกิน 60,000 บาท
- 2.2 หักค่าลดหย่อนบุคคล 30,000 บาท
- 2.3 หักค่าลดหน่อยบุตร คนละ 10,000 บาท

3. นำ 1) - 2) ผลเป็นรายได้หักค่าลดหย่อน
4. นำรายได้หักค่าลดหย่อยมาคิดหาภาษี

| รายได้            | ภาษี(%) |
| ----------------- | ------- |
| 0-350,000         | 0       |
| 350,001-500,000   | 5       |
| 500,001-750,000   | 10      |
| 750,001-1,000,000 | 15      |
| .>1,000,000       | 20      |

สมมุติเงินเดือน 200,000 บาท

1. 200,000 \* 12 = 2,400,000 บาท(รายได้ทั่งปี)
2. 2.1 60,000 + 30,000 + 0 = 90,000 บาท(ค่าใช้จ่ายส่วนตัว)
3. 1,500,000 บาท
4. 1,500,000 \* 20% = 170,000 บาท(ภาษีที่ต้องจ่าย)

code

#### require output

| id  | name | salary  | child | tax     |
| --- | ---- | ------- | ----- | ------- |
| 101 | A    | 200,000 | 0     | 170,000 |
| 102 | B    | 150,000 | 2     | xxx     |
| 103 | C    | 100,000 | 1     | xxx     |

```cpp
#include <iostream>
#include <string>

using namespace std;

struct employee
{
    string id;
    string name;
    float salary;
    int child;
    float tax;
};

//ป้อนพนักงานเก็บในตัวแปรระเบียน 1 มิติ
void input(employee item[], int&i){
    // int i=0;
    cout << "id=? ";
    cin >> item[i].id;
    while (item[i].id != "###"){
        cout << "name=? ";
        cin >> item[i].name;
        cout << "salary=? ";
        cin >> item[i].salary;
        cout << "child=? ";
        cin >> item[i].child;
        i++;
        cout << "id=? ";
        cin >> item[i].id;
    }
}

void output(employee item[], int size)
{
    float out; // เก็บภาษีที่ต้องจ่าย
    float total; // เก็บรายได้รวมทั่งปี
    for (int i=0; i < size; i++){
        total = item[i].salary * 12;
        if (total * 0.4 > 60000)
        {
            total = total - (total * 0.4);
        } else {
            total = total - 30000;
            total = total - (item[i].child * 10000);
        }
        if (total <= 350000){
            item[i].tax = 0.0;
        }
        elif (total <= 500000){
            item[i].tax = (total - 350000) * 0.05;
        } elif (total <= 750000){
            item[i].tax = 7500 + (total - 500000) * 0.1;
        } elif (total <= 1000000){
            item[i].tax = 7500 + 25000 + (total - 750000) * 0.15;
        } else {
            item[i].tax = 7500 + 25000 + 37500 + (total - 1000000) * 0.2;
        }
    }
    cout << "id name salary child tax" << endl;
    for (int i=0; i < size; i++){
        cout << item[i].id << " " << item[i].name << " " << item[i].salary << " " << item[i].child << " " << item[i].tax << endl;
    }
}

int main(){
    employee item[100];
    int size = 0;
    input(item, size);
    output(item, size);
    return 0;
}

```

## Example 2 Array 2d

ตย จองที่นั่ง
1A | 1B | stair | 1C | 1D
2A | 2B | stair | 2C | 2D
3A | 3B | stair | 3C | 3D
4A | 4B | stair | 4C | 4D

- การจองที่นั่ง
  R = reserve // จอง
  S = status // สถานะ
  Q = End // ออก
  Please select R/S/Q

- ตัวอย่างการจอง

กด R จองที่นั่ง
select seat =? 2A
ถ้าว่างจะให้ใส่ ชื่อ นามสกุล และเบอร์โทร
ถ้าไม่ว่างให้แจ้งว่ามีคนจองแล้วใ
ใช้ \*\* มาร์คว่ามีคนจองแล้ว

- code

```cpp
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct seat
{
    string number; // เช่น 1A, 1B, 1C, 1D
    bool is_free; // true = ว่าง, false = ไม่ว่าง
    string name; // ชื่อ ของคนจอง
    string tel;  // เบอร์โทร ของคนจอง
}

void init(seat item[8][4]){
    for (int row=0; row < 8; row++){
        for (int col=0; col < 4; col++){
            char seat_num[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
            char seats[4] = {'A', 'B', 'C', 'D'};
            item[row][col].number = seat_num[row] + seats[col];
            item[row][col].is_free = true;
        } // col
    } // row
}

void status(const seat item[8][4]){
    for (int row =0; row < 8; row++){
        for (int col=0; col < 4; col++){
            cout << setw(3) << item[row][col].number;
        }
        cout << endl;
    }
}

void reserved(const seat item[8][4]){
    string select;
    int row, col;
    cout << "select seat =? ";
    cin >> select;
    // int seat_num[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    // int seats[4] = {0, 1, 2, 3};

    if (select.at(0) == 'A'){
        row = 0;
    } elif (select.at(0) == 'B'){
        row = 1;
    } elif (select.at(0) == 'C'){
        row = 2;
    } elif (select.at(0) == 'D'){
        row = 3;
    } elif (select.at(0) == 'E'){
        row = 4;
    } elif (select.at(0) == 'F'){
        row = 5;
    } elif (select.at(0) == 'G'){
        row = 6;
    } elif (select.at(0) == 'H'){
        row = 7;
    }

    if (select.at(1) == 'A'){
        col = 0;
    } elif (select.at(1) == 'B'){
        col = 1;
    } elif (select.at(1) == 'C'){
        col = 2;
    } elif (select.at(1) == 'D'){
        col = 3;
    }

    if (item[row][col].is_free == true){
        cout << "name =? ";
        cin >> item[row][col].name;
        cout << "tel =? ";
        cin >> item[row][col].tel;
        item[row][col].number = "**";
        item[row][col].is_free = false;
    } else {
        cout << "seat is reserved" << endl;
    }
}

int main(){
    seat item[8][4];
    init(item); // กำหนดให้ที่นั่งว่างทุกที่นั่ง นำหมายเลยไลขไปใวาในฟิลเ์ number
    char ch;
    do {
        cout << "Select" << endl;
        cout << "R = reserve" << endl;
        cout << "S = status" << endl;
        cout << "Q = Quit" << endl;
        cout << "Please select R/S/Q : ";
        cin >> ch;
        switch (ch){
            case 'R':
            case 'r':
                reserved(item);
                break;
            case 'S':
            case 's':
                status(item);
                break;
        }
    } while (ch != 'Q' && ch != 'q');
    return 0;
}

```

# homework

1. ป้อนข้อมูลหนังสือ ประกอบด้วย รหัส, ชื่อ, ชนิด, ราคา
   โดยชนิดหนังสือแบ่งเป็น 3 ชนิด 1. คอมพิวเตอร์(computer) 2. คณิตศาสตร์(math) 3. สถิติ(stat)

- ป้อน

```
001 A 1 850
002 B 2 900
.
.
.
```

- ผลลัพธ์

```
1 computer
    001 A 850
    002 B 900
    _______
    1750
2 math
    007 H 1130
    _______
    1130
3 stat
    010 L 1050
    _______
    1050

Total 3930
```

2. จงป้อนข้อมูลสินค้า 4 ชนิด ประกอบด้วย รหัสสินค้า ชื่อสินค้า ราคาสินค้า และจำนวนในสต๊อก \

- ต้องให้ขายสินค้าและสืบค้นโดยใช้ **binary search** \
  **เงื่อนไข** \
  1.เรียงลำดับจากน้อยไปมาก \
  2.ป้อนรหัสไปสืบค้น เพื่อคิดราคาสินค้าแต่ป้อนได้หลายๆ หลายสินค้า หลายชิ้น เพื่อคิดเงิน \
  3.อัพเดทสิ้นค้าในสต๊อก
