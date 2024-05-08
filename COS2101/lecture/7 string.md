# String Class

การนำเข้าฟังก์ชั่น

```cpp
#include <string>. // บรรจุดฟังก์ชันที่เกี่ยวกับ string
```

1.การประกาศตัวแปร และ การกำหนดค่า

```cpp
string binary; // ประกาศตัวแปรชนิด string
binary = "1010"; // กำหนดค่าให้ตัวแปร binay
```

2.การกระทำ operation กับ ข้อมูลชนิด string

```cpp
int A,B;
int x;

string C,D;
string y;

A = 3; B = 4;
C = "3"; D = "4";

x = A + B; // 7
y = C + D; // 34
```

3.ฟังกืชั่น getline()
ดึง 1 บรรทัดจากผู้ใช้มาให้กับตัวแปร(รวมช่องว่าง)
เช่น

```
"This is a pen"
```

การเรียกฟังชั่นของ class string
1.การหาความยาวข้อความ (length)
length() คืนค่าเป็น int

```cpp
string A = "COS2101";

// การเรียกฟังก์ชั่น length()
int len = A.length(); // 7
cout << len << endl;
```

2.การดึงอักขระของตัวแปร string (at)

.at("ตำแหน่งที่ต้องการ") คืนค่าเป็น char

| index    | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| -------- | --- | --- | --- | --- | --- | --- | --- |
| A[index] | C   | O   | S   | 2   | 1   | 0   | 1   |

```cpp
string A = "COS2101";

// การเรียกฟังก์ชั่น at()

char c = A.at(0); // C
char c = A.at(1); // O
char c = A.at(2); // S

// ใช้ for loop ดึงอักขระทั้งหมด
for(int i = 0; i < A.length(); i++){
    char c = A.at(i);
    cout << c << endl;
}
```

3.การค้นหาข้อความในตัวแปร string (find)

.find("ข้อความที่ต้องการค้นหา") คืนค่าเป็น int

| index    | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| -------- | --- | --- | --- | --- | --- | --- | --- |
| A[index] | C   | O   | S   | 2   | 1   | 0   | 1   |

```cpp
string A = "COS2101";

// การเรียกฟังก์ชั่น find()

int index = A.find("O"); // 1
int index = A.find("S"); // 2
int index = A.find("CO"); // 0
int index = A.find("2101"); // 3
```

4.การแทรกข้อความในตัวแปร string (insert)

.insert("ตำแหน่งที่ต้องการแทรก","ข้อความที่ต้องการแทรก") คืนค่าเป็น string

```cpp
string A = "COS2101";

// การเรียกฟังก์ชั่น insert()

A.insert(3, "X"); // COSX2101
A.insert(0, "X"); // XCOS2101
A.insert(7, "X"); // COS2101X
```

5.การพิมพ์ข้อความทับข้อความเดิมในตัวแปร string (replace)

.replace("ตำแหน่งที่ต้องการแทรก","ข้อความที่ต้องการแทรก") คืนค่าเป็น string

```cpp

string A = "COS2101";

// การเรียกฟังก์ชั่น replace()

A.replace(2, 3, "INT"); // COINT01
A.replace(0, 3, "INT"); // INT2101
A.replace(4, 4, "INT"); // COS21INT
```

6.การลบข้อความในตัวแปร string (erase)

.erase("ตำแหน่งที่ต้องการลบ","จำนวนตัวอักษรที่ต้องการลบ") คืนค่าเป็น string

```cpp

string A = "COS2101";

// การเรียกฟังก์ชั่น erase()

A.erase(2, 3); // CO01
A.erase(0, 3); // 2101
A.erase(4, 4); // COS21
```

7.ดึงข้อความในตัวแปร string (assign)

.assign("ตัวแปรที่ต้องการดึงข้อความ","ตำแหน่งที่ต้องการดึง","จำนวนตัวอักษรที่ต้องการดึง") คืนค่าเป็น string

```cpp

string A = "This is a pen";

// การเรียกฟังก์ชั่น assign()

string B = A.assign(A, 10, 3); // pen
string B = A.assign(A, 0, 4); // This

```
