# Rucursive

การเขียนโปรแกรมเรียกตัวเอง
rucursive or recursion
สร้างฟังก์ชัน
ที่ภายในฟังก์ชันมีการเรียกใช้ฟังก์ชันตัวเอง
จะเปลี่ยน argument โดยลดลง หรือ เพิ่มขึ้น ในลักษณะเรียกซ้ำๆ จนถึงค่านึง จะหยุดการเรียกตัวเอง
เปลี่ยนการทำซ้า while, do-while, for ให้อยู่ในรูปเงื่อนไข

## EX 1

ฟังชั่น factorial
5! = 5*4*3*2*1 = 120
4! = 4*3*2\*1 = 24
1! = 1
0! = 1

flow

start > sum=1 > n > loop n=1 > sum=sum\*n > n=n-1 > loop n>1 > end

code

```cpp
// for
int factorial(int n) {
    int sum = 1;
    for (int i = n; i > 1; i--) {
        sum = sum * i;
    }
    return sum;
}

// i | sum
// 5 | 1*5 = 5
// 4 | 5*4 = 20
// 3 | 20*3 = 60
// 2 | 60*2 = 120
// 1 stop

```

รูปแบบการเรียกตัวเอง
ต้องมีคำสั่งที่ทำซ้ำโดยนำข้อมูลในรอบที่แล้ว มาดำเนินการในรอบปัจจุบัน นั่น
sum = sum + i;
sum = sum - i;
sum = sum \* i;
sum = sum / i;

sum ค่าใหม่ในรอบปัจจุบัน

if (เงื่อนไขรที่หยุดการกระซ้ำ){
return value;
}

return ตัวเองโดยส่ง argument ใหม่ไม่ให้ฟังค์ชั่นเป็นการประมวลผลในรอบปัจจุบัน

```cpp
int fac(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * fac(n-1);
}
```

เรียกใช้ fac(3)

| รอบที่ | n   | return      | process |
| ------ | --- | ----------- | ------- |
| 1      | 3   | fac(2) \* 3 | 1*2*3   |
| 2      | 2   | fac(1) \* 2 | 1\*2    |
| 3      | 1   | 1           | 1       |

## EX 2

จงเขียนฟังชั่นในการหา x^y การหนดให้ x = float, y = int

เช่น
3^2 = 3*3 = 9
3^1 = 3
3^0 = 1
3^-1 = 1/3
3^-2 = 1/3*1/3 = 1/9

| 3^-2 | 3^-1 | 3^0 | 3^1 | 3^2 |
| ---- | ---- | --- | --- | --- |
| 1/9  | 1/3  | 1   | 3   | 9   |

พิจารณากรณีที่เป็นเลขเต็มบวก
3^3 = 3*3^2 = 3*9 = 27
3^2 = 3*3^1 = 3*3 = 9
3^1 = 3*3^0 = 3*1 = 3
3^0 = 1

พิจารณากรณีที่เป็นเลขเต็มลบ
3^-3 = 1/3^3 = 3^-2 = 1/9
3^-2 = 1/3^2 = 3^-1 = 1/3
3^-1 = 1/3^1 = 3^0 = 1
3^0 = 1

pow(x, y) = 1/x \* pow(x, y+1)

```cpp

float pow(float x, int y){
    if (y == 0){
        return 1.0;
    }
    else if (y > 0){
        return x * pow(x, y-1);
    }
    else if (y < 0){
        return (1.0/x) * pow(x, y+1);
    }
}

```

pow(3, 3);

3 _ pow(3, 2)
3 _ pow(3, 1)
3 \* pow(3, 0)

return 3 _ 3 _ 3 \* 1 = 27

## EX 3

ฟังชั่น fibonacci

| year | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |
| ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| fib  | 1   | 1   | 2   | 3   | 5   | 2   | 13  | 21  | 34  |

fibo(y) = 1 if y == 1 or y == 2 or fibo(y-1) + fibo(y-2)

fibo(5) = fibo(4) + fibo(3)

```cpp

int fibo(int y){
    if (y == 1 || y == 2){
        return 1;
    }
    return fibo(y-1) + fibo(y-2);
}

```

fibo(4) = fibo(3) + fibo(2)
fib(3) = fib(2) + fib(1)

## EX 4

จงหาคำตอบโดยเรียกใช้ n(1,2) =?

int n(int m, int n){
if (m == 0){
return n+1;
} else if (m>0 && n==0){
return n(m-1, 1);
} else {
return n(m-1, n(m, n-1));
}
}

process :

> n(1, 2) = n(0, 3) = 3+1 = 4

## EX 5

การสร้าง binary search

array | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
item | 34 | 22 | 53 | 89 | 72 | 64| 77 |

index = search(item, 89); // 3
index = search(item, 90); // -1 หาไม่เจอ

ถ้าข้อมูลมีขนาดใหญ่จะเสียเวลาในการค้นหามาก

1. นำข้อมูลมาเรียงลำดับจากน้อยไปมาก
   array | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
   item | 22 | 34 | 53 | 64 | 72 | 77 | 89 |

2. แบ่งข้อมูลออกมาเป็น 2 กลุ่ม โยดยหาช่องกลางของข้อมูล(ชั้)
   mid = (first + last)/2

mid = (0 + 6)/2 = 3

3. นำ key ที่ต้องการค้นหามาเปรียบเทียบกับช่องกลาง

if (key == item[mid]){
return mid;
} else if (key < item[mid]){
// ลดกลุ่มข้อข้อมูลลงเหลือแค่ทางซ้าย ของ mid
last = mid - 1;
else if (key > item[mid]){
// ลดกลุ่มข้อข้อมูลลงเหลือแค่ทางขวา ของ mid
first = mid + 1;
// เรียกตัวเองเพื่อหาข้อมูล
} else if (first > last){
return -1; // หาไม่เจอ
}

code

```cpp

int BinSearch(int item[], int first, int last, int key){
    int mid;
    mid = (first + last)/2;
    if (first > last){
        return -1;
    } else if (key == item[mid]){
        return mid;
    } else if ((key) < item[mid]){
        return BinSearch(item, first, mid-1, key);
    } else {
        return BinSearch(item, mid+1, last, key);
    }
}
```

## EX 6

เกมส์ หาฮานอย
the twon of hanoi
ย้ายสิ่งของจาก town a ไป town b
สิ่งของในขนาดไม่เท่ากัน ขนาดเล็กซ้อนทับขนาดใหญ่เท่านั้น
โดยย้ายได้ครั่งละ 1 ชื้น โดยขนาดใหญ่ซ้อนทับเล็กไม่ได้
มี town c ช่วยเก็บสิ่งของได้

- town(A, B, C, 1); // มีสิ่งของ 1 ชิ้น

a to b

ผล
Move object 1 from A to B

- town(A, B, C, 2);

move object 1 from A to C
move object 2 from A to B

move object 1 from C to B

- tower(A, B, C, 3);

1. move object 1 and 2 to C
   โดย tower(A, C, B, 2);
2. move 1 from A to B
3. move object from C to B
   โดย tower(C, B, A, 2);

```cpp

void hanoi(char from, char to, char temp, int n){
    if (n==1){
        cout << "Move object 1 from " << from << " to " << to << endl;
    } else {
        hanoi(from, temp, to, n-1);
        cout << "Move object " << n << " from " << from << " to " << to << endl;
        hanoi(temp, to, from, n-1);
    }
}
```

# Homework

1. จงป้อนอักขระทางแป้นพิมพ์เก็บใน array 1 มิติ ให้หา Palindrome ของอักขระที่ป้อนเข้ามา
   เช่น
   ABCBA
   11
   COST
   ARRY
   11211

###

```ตย.
ABCBA คือ Palindrome
11 คือ Palindrome
11211 คือ Palindrome
COST ไม่ใช่ Palindrome
ARRY ไม่ใช่ Palindrome
```

- 1.1 เขียนใช้ loop
- 1.2 เขียนใช้ recursive

2. แปลงเลขฐาน 10 เป็นฐาน 2 โดยใช้ recursive(ฟังก์ชันที่เรียกตัวเอง)
