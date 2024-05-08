# Stack and <a href="#Queue">Queue</a>

โครงสร้างข้อมูลที่มีการปฎิบัตงาน

li-fo
last in first out
สมาชิกที่ทำหลังจะนำออกก่อน
เช่น การหา่า factorial โดย เรียกตัวเอง

```
Fact(5) -> Fact(4) -> Fact(3) -> Fact(2) -> Fact(1) -> 1
```

การนำสมาชิกเข้าและออกเพียงทางเดียว
การนำเข้ากองซ้อน เรียกว่า push
การนำออกกองซ้อน เรียกว่า pop

- การสร้างกองซ้อน ทำได้ 2 วิธี

1. **ใช้ array 1 มิติ**

| index | data |
| ----- | ---- |
| 5     | ?    |
| 4     | ?    |
| 3     | ?    |
| 2     | ?    |
| 1     | ?    |
| 0     | ?    |

ตัวแปร top จะเก็บ top ชี้ตัวบนสุด ควบคุมการนำสมาชิกเข้าหรือออกกองซ้อน
max หรือ size = 6
stack ว่าง top = -1

- การ push
  1.ตรวจสอบว่า stack ไม่เต็ม?
  กรณีถ้าเต็ม 'stack overflow' top ชี้ตัวบนสุด
  กรณีไม่เต็ม top = top + 1
  ให้ top ไปชี้ที่ข้อมูลที่ต้องการเพิ่ม

```cpp
stack[top] = 'item'
push('a');
push('b');
```

| index | data |
| ----- | ---- |
| 1     | b    |
| 0     | a    |

top = 1

- การ pop
  1.ตรวจสอบว่า stack ว่ามีข้อมูลหรือไม่?
  ให้ top = -1 แสดงว่า stack ว่าง "stack underflow"

กรณีมีข้อมูล

```cpp
item = stack[top];
top = top - 1;
```

นำออก 'b' -> 'a'

| index | data |
| ----- | ---- |
| b     | 1    |
| a     | 0    |
| -1    | -1   |

2. Linked Stack
   นำข้อมูล singly linked list มาใช้เป็นกองซ้อน

- การ push
  ตัวแปร top จะเก็บ address ของโหนดตัวบนสุดของ stack
  กรณี stack ว่าง top = NULL

push(79);

| data | link |
| ---- | ---- |
| NULL | NULL |

p->data = 79;
p->link = top;

| data | link |
| ---- | ---- |
| 79   | NULL |

```cpp
top = p; //ถ้าเป็น node แรก ให้ top ชี้ไปที่ node แรก
```

push(68);
แทรกโหนดใหม่เป็นโหนดแรก และ top ชี้ไปที่โหนดแรก

```cpp
p->link = top;
top = p;
```

| index | data | link |
| ----- | ---- | ---- |
| 0     | 68   | 79   |
| 1     | 79   | NULL |

```
push(62);
p->link = top;
top = p;
```

| index | data | link |
| ----- | ---- | ---- |
| 0     | 62   | 68   |
| 1     | 68   | 79   |
| 2     | 79   | NULL |

```
top = 62 -> 68 -> 79 -> NULL
```

- การ pop

การนำสมาชิกที่ top ชี้อยู่ออกจาก stack
ถ้า top != NULL

```cpp
{
    item = top->data;
    temp = top;
    top = top->link;
    delete(temp); // while or recursive
}
```

## ตัวอย่าง 1

การแปลงนิพจน์ infix เป็น postfix

- พิพจน์ infix คือ

| opr | oparator | opr        |
| --- | -------- | ---------- |
| A   | +        | B          |
| A   | +        | 3          |
| A   | +        | B \* C - D |

คอมไพเลอร์ จะลดการค้นหาตัวกระทำ จะทำการแปลงให้ตัวกระทำ อยู่ในลำดับที่ถูกต้อง โดยลดการค้นหา

1. A + (B + C) - D

- พิพจน์ postfix คือ

| opr    | opr2 | oparator |
| ------ | ---- | -------- |
| A      | B    | +        |
| A      | 3    | +        |
| ABC\*+ | D    | -        |

## วิธีแปลง

1. manual
   - 1.1 ใส่วงเล็บตามลำดับความสำคัญ
   - 1.2 นำ operator แทนที่วงเล็บปิด
   - 1.3 นำ วงเล็บเปิดทิ้ง

จาก A + B _ C + D \
1.1 `((A + (B _ C)) + D)`\
1.2`(A + (BC* + D-))`\
1.3`A + BC* + D-`

### งาน

**`A *B + C* D/E`**

```
((A * B) + (C * (D / E)))
AB* + CD*E/+
```

**`A * (B + C) - (D/E)`**

```
((A * (B + C)) - (D / E))
ABC+* DE/-
```

- ข้อสังเกต
  - operand อยู่ในลำดับ
  - operator จะสลับตามลำดับความสำคัญ

#### 1. การแปลงนิพจน์ infix เป็น postfix โดยใช้ stack

- ออกสอบ มีตารางให้ ให้แปลงเอง

| token     | postfix                 | stack                    |
| --------- | ----------------------- | ------------------------ |
| A         | A                       | `empty`                  |
| '\*       | A                       | \* `(ถ้า stack ว่าง)`    |
| B         | AB                      | \* `(isp)`               |
| '+ (icp)  | AB*`(pop* แล้ว push +)` | +                        |
| C         | AB\*C                   | +                        |
| '\* (icp) | AB\*C                   | +\* `(push icp > isp)`   |
| D         | AB\*CD                  | +_ `(pop _ แล้ว push D)` |
| / (icp)   | `AB*CD*`                | +/ `(push icp > isp)`    |
| E         | `AB*CD*E`               | +/ `(pop / แล้ว push E)` |

จะ pop ตัวกระทำ
`AB*CD*E/+`

## ตัวอย่าง 2

A \* (B+C) - (D/E)

| token     | postfix   | stack                           |
| --------- | --------- | ------------------------------- |
| A         | A         | `empty`                         |
| '\*'      | A         | \* `(ถ้า stack ว่าง)`           |
| '('       | A         | \*( `(push '(' ลง stack)`       |
| B         | AB        | \*( `(isp)`                     |
| '+' (icp) | AB        | \*(+ `(isp ลำดับต่ำสุด)`        |
| C         | ABC       | \*(+ `(จะทำการ pop จนเจอ ')' )` |
| ')'       | ABC+      | \*                              |
| '-'       | ABC+\*    | -                               |
| '('       | ABC+\*    | -(                              |
| D         | ABC+\*D   | -(                              |
| '/'       | ABC+\*D   | -(/ `(push icp > isp)`          |
| E         | ABC+\*DE  | -(/ `(pop / แล้ว push E)`       |
| ')'       | ABC+\*DE/ | - `(push จนเจอ '(')`            |

จะ pop ตัวกระทำ
ABC+\*DE/-

## coding

```cpp
#include <iosteam>
#include <string>

using namespace std;

struct node
{
    char data;
    node *link;
};

void input(string infix){
    cout << "Infix : ";
    cin >> infix;
}

void push(node *&top, char oparator){
    node *p;
    p = new node;
    p->data = oparator;
    p->link = NULL;

    if (top == NULL){
        top = p; // แทรกโหนดใหม่เป็นโหนดแรก
    } else {
        p->link = top;
        top = p;
    }
}

void pop(node *&top, char& oparator){
    node *temp;
    if (top != NULL){
        oparator = top->data;
        temp = top;
        top = top->link;
        delete(temp);
    } else {
        cout << "stack underflow";
    }
}

int icp(char oparator){
    switch (oparator)
    {
        case '(':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case ')':
            return 1;
    }
    return 0;
}

int isp(node *top) // จะนำข้อมูลที่ ท๊อป ชี้อยู่มาหาลำดับความสำคัญ สังเกตุ ไม่มี &
{
    switch (top->data)
    {
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
    }
    return 0;
}

void process(string infix, string& postfix){
    node *top; // top data in stack
    top = NULL;
    int len = infix.length(); // total length of infix
    char oparator;
    for (int i=0; i < len; i++)
    {
        if (
            infix.at(i) >= 'A' &&
            infix.at(i) <= 'Z' ||
            infix.at(i) >= 'a' &&
            infix.at(i) <= 'z' ||
            infix.at(i) >= '0' &&
            infix.at(i) <= '9'
        )
        {
            postfix += infix.at(i);
        } else if (
            top == NULL ||
            infix.at(i) == '(' ||
            icp(infix.at(i)) > isp(top)
        )
        {
            push(top, infix.at(i);)
        } else if (infix.at(i) == ')')
        {
            pop(top, oparator);
            while (oparator != '(')
            {
                postfix += oparator;
                pop(top, oparator);
            }
        } else { // case icp <= isp
            while (
                top != NULL
                && icp(infix.at(i))
                <= isp(top)
            ) {
                pop(top, oparator);
                postfix += oparator;
            }
            push(top, infix.at(i));
        }
    } // end for
    // token all infix

    while (top != NULL)
    {
        pop(top, oparator);
        postfix += oparator;
    }
}

int main(){
    string infix, postfix;
    postfix = "";
    input(infix);
    process(infix, postfix);

    cout << "postfix : " << postfix << endl;

    return 0;
}
```

## การบ้าน

1. ให้ป้อน postfix string เป็นนิพจน์ คณิคศาสตร์ ที่ oprand เป็นตัวเลข
   เช่น \
   `3 + 4 + 5` ป้อน `345*+` \
   `1*2+3*4` ป้อน `12*34*+`

จงหาผลลัพธ์ของ postfix string

- ใช้ stack จะเก็บ oprand เท่านั้น

# Queue

โครวสร้างข้อมูลที่เรียกว่า fi-fo
first in first out

เก็บได้ 2 ลักษณะ

| 0   | 1   | 2   | 3   | 4   | 5   |
| --- | --- | --- | --- | --- | --- |
| 31  | 65  | 25  | 34  | ?   | ?   |

front ชี้ไปที่ตำแหน่งนำออก
rear ชี้ที่ตำแหน่งสุดท้ายของคิว

```
front -> 31 -> 65 -> 25 -> 34 -> rear
```

การนำสมาชิกเข้าคิว (Enqueue)

จะกระทำชี้โหนดสุดท้าย ที่ rear ชี้อยู่

```cpp

void enqueue(node*& front, node*& rear){
    node* p = new node;
    cout << "data : ";
    cin >> p->data;
    p->link = NULL;

    if (rear == NULL){
        front = rear = p;
    } else {
        rear->link = p;
        rear = p;
    }
}

void dequeue(node*& front, node*& rear, char item)
{
    node* temp;
    if (front != NULL)
    {
        item = front->data;
        temp = front;
        front = front->link;
        delete(temp);
    } else {
        cout << "queue underflow";
    }
}

```

## ตัวอย่าง 1

การหาค่า waiting time and turn around time ของ process

| process | ระยะเวลาที่ใช้ cpu (วินาที) |
| ------- | --------------------------- |
| A       | 23                          |
| B       | 4                           |
| C       | 4                           |

**waiting time** คือ ระยะเวลาที่ process ต้องรอในคิว \
**turn around time** คือ ระยะเวลาที่ process ใช้ทั้งหมด

`turn_around_time = waiting_time + running_time`

- สรุป

| process   | waiting time | turn around time |
| --------- | ------------ | ---------------- |
| A         | 0            | 23               |
| B         | 23           | 27               |
| C         | 27           | 31               |
| \*Average | 16.4         | 27               |
