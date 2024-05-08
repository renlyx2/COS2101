## Array 2 มิติ

กลุ่มของข้อมูลมาเก็บในลักษณะของแถวแลบคอลั่ม

10 20 34 68 79 24
ระขุแถวและคอลั่ที่เก็บ เช้่นเก็บ 2 แถว 3 คอลั่ม จะเก็บได้ 6 ข้อมูล

<!-- colunm 2 x 3  -->

| 10 | 20 | 34 |
| 68 | 79 | 24 |

```cpp
int a[2][3] = {{10,20,34},{68,79,24}};

// read data
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cout << a[i][j] << " ";
    }
    cout << endl;
}
int A =[2][3] = {{1,2,3}, {4,5,6}};
// {1,2,3} คือ แถวแรก
// {4,5,6} คือ แถวที่สอง
int B[3][2] = {{1,2}, {3,4}, {5,6}};

// zero array
int A [2][3] = {0};
```

example1
รับข้อมูล matrix A and B
ขนาด 3x3 จงหา

1. A+B
2. A\*B
3. Transpose of matrix A

// Matrix A = 1 0 2 0 1 1 2 2 2
// Matrix B = 1 1 2 1 0 1 2 0 2

```
A
| 1 0 2 |
| 0 1 1 |
| 2 2 2 |

B
| 1 1 2 |
| 1 0 1 |
| 2 0 2 |


1. A+B
| 2 1 4 |
| 1 1 2 |
| 4 2 4 |
// บวกในแต่ละตำแหน่ง

2. A*B
| 5 1 6 |
| 3 1 4 |
| 8 4 10 |
```

code

```cpp
#include <iostream>

using namespace std;
// A B C D

// void inputA(int a[][3]){
// ต้องระบุขนาดของ array ที่รับเข้ามา
void input(int x[3][3]){
    int r, c;
    for (r=0); r<3; r++){
        for (c=0; c<3; c++){
            cin >> x[r][c];
        }
    }
}

// ห้ามตั่งตัวแปรซ้ำ
// x+y = z
void AddMatrix(const int A[][3], const int B[][3], int D[3][3]){
    for (int row =0; row < 3; row++){
        for (int col  =0 ; col < 3; col++){
            for (int k=0; k <3; k++){
                D[row][col] += A[row][k] * B[k][col];
            }
        }
    }
}

// ห้ามตั่งตัวแปรซ้ำ
// x*y = z
void MultiplyMatrix(const int x[][3], const int y[]][3], int z[][3]){
    int r,c,k;
    for (int r =0; r<3, r++){
        for (int c=0; c <3; c++){

        }
    }
}

void PrintMatrix(const int x[][3]){
    #include <iomanip> // พิมพ์ให้สวยงาม

    for (int i = 0; i < 3; i++){
        for (int k=0; k<3; k++){
            // cout << x[i][j];
            cout << setW(3) << x[i][k];
        }
        cout << endl;
    }
    // func setW

}

void TransposeMatrix(const int x[][3]){
    for (int r =0; r< 3; r++){
        for int (c = 0; c<3; c++){
            cout << setW(3) << x[c][r];
        }
        cout << endl;
    }
}


int main(){
    int A[3][3], B[3][3], C[3][3], D[3][3];
    D[3][3] = {0};

    cout << "Matrix A" << endl;
    input(A);
    cout << "Matrix B" << endl;
    input(B);

    AddMatrix(A, B, C);
    MultiplyMatrix(A, B, D);
    PrintMatrix(C);
    PrintMatrix(D);
    TransposeMatrix(A);

    return 0;
}
```

ex2
บริษัทผลิตเสื้อ มี ชนิด อยู่ 3 แบบ
type 1 แขนสั้น
type 2 แขนยาว
type 3 แจ็คเก็ต
แต่ละแบบมีทั่งหมด 5 ขนาดได้
ซึ่งแตกต่างกันดังนี้

# price

| type | S   | M   | L   | XL  | XXL |
| ---- | --- | --- | --- | --- | --- |
| 1    | 200 | 220 | 250 | 280 | 300 |
| 2    | 250 | 280 | 300 | 320 | 350 |
| 3    | 450 | 500 | 550 | 580 | 600 |

รวบรวมการสั่งซื้อเสื้อแต่ละชนิดแต่ละไซต์
Input

```
type 1
    s = ? 10
    m = ? 20
    l = ? 30
    xl = ? 40
    xxl = ? 50
type 2
    s = ? 5
    m = ? 5
    l = ? 3
    xl = ? 30
    xxl = ? 40
type 3
    s = ? 10
    m = ? 20
    l = ? 30
    xl = ? 35
    xxl = ? 15
```

5 row 3 col

# item

| row\col | s   | m   | l   | xl  | xxl |
| ------- | --- | --- | --- | --- | --- |
| 1       | 10  | 20  | 30  | 40  | 50  |
| 2       | 5   | 5   | 3   | 30  | 40  |
| 3       | 10  | 20  | 30  | 35  | 15  |

Output ราคายอดรวมของแต่ละชนิด ทั้งหมด

# design program

- main มีตัวแปร item 3x5, cost 3x5

- input ป้อนจำนวนชนิดเสื้อและชนิดเสื้อ เก็บในตัวแปร item

- output คำนวนยอดรวม และพิมพ์ออกทางจอภาพ

```cpp
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string TYPE[3] = {"type1", "type2", "type3"};
string SIZE[5] = {"S", "M", "L", "XL", "XXL"};
int COST[3][5] = {
    {200, 220, 250, 280, 300},
    {250, 280, 300, 320, 350},
    {450, 500, 550, 580, 600}
};

void input(int item[3][5]){
    for ( int row = 0; row < 3; row++){
        cout << "type" << TYPE[row] << endl;
        for (int col = 0; col < 5; col++){
            cout << SIZE[col] << " = ? ";
            cin >> item[row][col];
        }
    }
}

void output(const item[3][5]){
    double amount; // เก็บจำนวนเงินรวมที่คำนวนของแจ่ละ type แต่ละ size
    double total = 0.0; //เก็บจำนวนเงินรวมทั้งหมด
    cout << "" Invoic << endl;
    cout << ""______________________________________ << endl;
    cout << "type size quality price/unit amount" << endl;

    for (int row = 0; row < 3; row ++ ){
        // cout << TYPE[row] << " ";
        // cout << SIZE[row] << " ";
        for (int col = 0; col < 5; col ++){
            cout << TYPE[row] << " ";
            cout << SIZE[col] << " ";
            cout << item[row][col] << " ";
            cout << COST[row][col] << " ";
            amount = item[row][col] * COST[row][col];
            cout << amount << endl;
            total += amount;
            // ใช้ setw ในการจัดรูปแบบการพิมพ์ได้
        }
        cout << endl;
    }
    cout << "Total = " << total << endl;
}

int main(){
    int item[3][5]; // เก็บจำนวนลูกค้าสั่ง
    Input(item);
    Output(item);
    return 0;
}
```

## Homework

1.จงรับคะแนนของ นศ n คน เก็บใน array 2 มิติ และ จงหาคะแนนเฉลี่ยของนักศึกษาทั้งหมด

| X   | 0   | 1   | 3   | 4   |
| --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   |
| 2   | 0   | 0   | 0   | 0   |
| 3   | 0   | 0   | 0   | 0   |

input 50 60 60 70 25 -999

| คะแนน  | เกรด |
| ------ | ---- |
| '>=80' | G    |
| 60-79  | P    |
| <60    | F    |

2. บริษัทแห่งหนึ่งมีการให้เงินพิเศษให้พนักงาน
   ในปี 2565 โดยนำจำนวนรถยนต์ที่ขายได้ในแต่ละเดือนมาคำนนวหาค่าเว้นพิเศษ
   สมมุติว่ามีพนักงงาน 3 คน
   12 mouth

| name | jan | feb | mar | apr | may | jun | jul | aug | sep | oct | nov | dec |
| ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| john | 10  | 5   | 8   | 15  | 10  | 3   | 5   | 8   | 15  | 10  | 3   | 5   |
| jane | 8   | 15  | 10  | 3   | 5   | 8   | 15  | 10  | 3   | 5   | 8   | 15  |
| jim  | 10  | 3   | 5   | 8   | 15  | 10  | 3   | 5   | 8   | 15  | 10  | 3   |

จงหา

1. หายอดรวมขายรถในแต่ละคน
   john = ?
   jane = ?
   jim = ?
   ใครขายได้มากที่สุด คนไหน
2. หาเงินพิเศษ พนักงานที่
   **ขายรถได้เกิน 100 คัน ได้เงินโบนัส 8 เดือน**
   **ขายรถได้ 80-99 8 คัน ได้เงินโบนัส 5 เดือน**
   **ขายได้ 50-79 คัน ได้เงินโบนัส 3 เดือน**
   **ต่ำกว่า 50 คัน ได้เงินโบนัส 1 เดือน**
