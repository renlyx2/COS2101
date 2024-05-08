# Linked List ลิสต์เชื่อมโยง

รายการเชื่อมโยง

แตกต่างจาก array หรือ ระเบียน -> มีการจองเนื้อที่ก่อนทำงาน

ข้อเสีย
1 เนื้อที่ไม่หมด มีการจัดสรรค์ไม่มีประสิทธิภาพ
2 การแทรก และ ลบ เสียเวลาในการเคลื่อนย้่าย

รายการเชื่อมโยง จัดสรรเนื้อที่เมื่อค้องการเก็บเท่านั่น
ที่มีข้อมูล นศ 3คนไม่จองเนื้อที่ก่อน
ร้องขอไปยังระบบจะจัดสรรให้ทีละคน ใช้คำสั่ง new

A -> [] -> [] -> []

การจัดสรรรเนื้อที่แบบพลวัตร (dynamic)
ตัวชี้ข้อมูล เป็นชนิดข้อมูลที่เรียกว่า pointer(พอยเตอร์)

เก็บตำแหน่งที่อยู่ (address) ของข้อมูล

- การประกาศตัวแปร pointer (ออกสอบ)

```cpp

type *variable;

int A; // ตัวแปรปกติ , A=3; , address ของ A คือ 1010
int *B; // ตัวแปร pointer B[] เก็บ address ของข้อมูลที่เป็น intในหน่วยความจำ

```

| address | 1010 | 1012 | 1014 | 1016 |
| ------- | ---- | ---- | ---- | ---- |
| A       | 3    | 5    | 7    | 9    |

# singly linked list ลิสต์เชื่อมโยงแบบทางเดียว

- ประกาศ โครงสร้างข้อมูล

```cpp

struct student{
    string id;
    string name;
    int score;
};

student item[5];
// การให้ค่ากับตัวแปร struct
item[0].id = "101";
item[0].name = "A";
item[0].score = 80;

item[1].id = "102";
item[1].name = "B";
item[1].score = 65;

```

- ใช้ตัวแปร pointer ชี้ข้อมูลตัวถัดไป

```cpp
struct student{
    string id;
    string name;
    int score;
    student *link; // เก็บ address ของข้อมูลตัวถัดไป
};
```

| id  | name | score | link |
| --- | ---- | ----- | ---- |
| 101 | A    | 80    | 1012 |

การประกาศตัวแปรรเพียงกำหนดตัวแปร ที่เก็บ address ของคนแรก เราสามารถเขียนโปรแกรมเพื่อเดินทาง
ไปยังข้อมูลต่อๆ ไปได้โดยข้อมูลสุดท้ายมี link = NULL สิ้นสุดการเชื่อมโยง

```cpp
student *data1;
student *data2;

data1 = new student;
data2 = new student;
//ร้องขอข้อมูล บลาๆ โดยให้ data1 เก็บเนื้อที่นั่น address
```

| data1 | data2 |
| ----- | ----- |
| 101   | 102   |
| A     | B     |
| 80    | 65    |
| NULL  | NULL  |

- การให้ค่ากับตัวแปรชนิด pointer

```cpp

data1->id = "101";
data2->id = "102";
data1->name = "A";
data2->name = "B";
data1->score = 80;
data2->score = 65;
data1->link = NULL;
data2->link = NULL;

```

- การเชื่อมต่อ node ใน linked list

1. เชื่อมเป็นโหนดแรก
2. เชื่อมระหว่างโหนด
3. เชื่อมไปโหนดสุดท้าย

**หมายเหตุ:** การระบุ address ของโหนด ที่ต้องการเชื่อมต่อ

```cpp
data1->link = data2;
// data1->[101|A|80|data2] ->[102|B|65|NULL]
// P ->[100|2|60] (new node)
```

1.แทรกโหนดใหม่ เป็น node แรก

```cpp
p->link = data1;
first = p;
// first -> [100|2|60|data1] ->[101|A|80|data2] ->[102|B|65|NULL]
```

2.แทรกโหนดใหม่ เป็นโหนดสุดท้าย

```cpp
// P -> [107|x|50]
// ต้องหา node สุดท้าย
student *first, *last;
last = first; // กำหนด last เป็น node แรก
while(last->link != NULL){
    last = last->link;
}
last->link = p;
```

3.แทรกโหนดใหม่ ระหว่างโหนด

```cpp
// first -> [100|2|60|data1] ->[101|A|80|data2] ->[102|B|65|NULL] ->[107|x|50]
// p -> [105|q|70]

student *pre, *post; // pre = ก่อน post = หลัง
pre = NULL;
post = first;
// จะแทรกระหว่าง 105 กับ 107
while(p->id > post->id){
    pre = post;
    post = post->link;
}
pre->link = p;
p->link = post;
```

- การลบโหนด ใน linked list

```cpp
// first_2 -> [50] -> [70] -> [80] -> [80]
// วิธีที่แรก 1 ลบโหนดแรก
student *del; // โหนดที่จะลบ
student *pre; // โหนดก่อนโหนดที่จะลบ

pre = NULL;
del = first_2;
while(del != NULL && del->score != 50){ // หาโหนดที่มีคะแนน 50
    pre = del;
    del = del->link;
}
if (pre == NULL){ // ถ้าโหนดที่จะลบ เป็นโหนดแรก
    first_2 = del->link; // ชี้ first_2 ไปที่โหนดถัดไป
    delete del; // delete การคืนหน่วยความจำ
}
// วิธีที่ 2 ลบระหว่างโหนด และ ลบโหนดสุดท้าย
else if (del == NULL){
    cout << "Not found" << endl;
} else {
    pre -> link = del->link;
    delete del;
}
```

## ตัวอย่าง 1

สร้างรายการโนงของสมการโพลิโนเมียล
ชนิด 2 ตัวแปร

- ป้อน

```c
สัมประสิทธิ์ ค่ายกกำลัง
3 5
4 7
-6 0
2 1
-9 -3
0 จบการป้อน
```

| noef | power     | link |
| ---- | --------- | ---- |
| 3    | 5         | ?    |
| 4    | 7         | ?    |
| -6   | 0         | ?    |
| 2    | 1         | ?    |
| -9   | 3         | ?    |
| 0    | จบการป้อน | ?    |

โดยสร้าง linked list ให้กำลังมากอยู่ลำดับบก่อนกำลังน้อย
ลิงค์ว่าง first = NULL

```
first = [3][5]
first = [4][7] -> [3][5]
first = [4][7] -> [3][5] -> [-6][0]
first = [4][7] -> [3][5] -> [2][1] -> [-6][0]
first = [4][7] -> [3][5] -> [-9][3] -> [2][1] -> [-6][0]

y(x) = 4x^7 + 3x^5 - 9x^3 + 2x + -6
```

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

struct node{
    int coef; // สัมประสิทธิ์
    int power; // ค่ายกกำลัง x
    node *link;
};

void input(node *&); // การอ้างอิงตัวแปร address ของตัวแปรที่ main ส่งมา | & เปลี่ยนแปลงข้อม฿ลที่ป้อน ก่อน ไม่มีข้อมูล
void output(node *); // นำข้อมูลที่ป้อนมาแสดง อ่านเท่านั้น

int main(){
    node *first;
    first = NULL;
    input(first);
    output(first);
    return 0;
}

void input(node *& first)
{
    node *p; // ชี้โหนดใหม่
    node *pre; // ชี้โหนดก่อนแทรก
    node *post; // ชี้โหนดหลังแทรก
    int data; // รับจ้อมูล ว่าเป็น 0 หรือไม่

    cout << "coef = ?";
    cin >> data;
    while(data != 0){
        p = new node; // ร้องขอ 1 โหนดใช้ p ชี้ ไปโหนดใหม่
        p->coef = data; // สัมประสิทธิ์
        cout << "power = ?";
        cin >> p->power; // ค่ายกกำลัง
        p->link = NULL; // ลิงค์ว่าง
        if (first == NULL){
            first = p; // โหนดแรก
        } else {
            pre = NULL;
            post = first;
            // หาตำแหน่งที่จะแทรก
            while(post != NULL && post->power < p->power){
                pre = post;
                post = post->link;
            }
            if (pre == NULL){
                p->link = first;
                first = p;
            } else { // แทรกเข้าไป ระหว่าง pre และ post
                pre->link = p;
                p->link = post;
            }
        }
    }
}

void output(node *first){
    while (first != NULL){
        if (first->coef > 0){
            cout << " + " << first->coef;
        } else {
            cout << " - " << first->coef;
        }

        if (first->power > 0){
            cout << "x^" << first->power;
        }
        first = first->link;
    }
    // สามารถเขียนเป็น ฟังชันก์ recursive ได้
}
```

## การบ้าน

1. ให้ป้อนข้อมูลนักศึกษา ประกอบด้วย id, name, score \
   ให้ลบข้อมูลนักศึกษา โดยป้อน id \
   ให้เรียงไอดีจากน้อย -> มาก
