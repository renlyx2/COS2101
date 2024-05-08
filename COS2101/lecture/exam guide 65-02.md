# Guide Exam 65-02

[แนวข้อสอบ](/src/COS/COS2101/lecture/exam%20guideline%2065-02.md)

### Algorithm

- if else statement, switch case statement, while loop, for loop, do while loop, recursion

### String

**อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/7%20string.md) | [การบ้าน](/src/COS/COS2101/homework/7.cpp)

### Array

- 1 มิติ
  **อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/8%20array.md) | [การบ้าน](/src/COS/COS2101/homework/8.cpp)
- 2 มิติ
  **อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/9%20array%202d.md) | [การบ้าน](/src/COS/COS2101/homework/9.cpp)

### Linked list

**อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/12%20linked%20list.md) | [การบ้าน](/src/COS/COS2101/homework/12_v4.cpp)

- การเพิ่มโหนดใหม่

```cpp
struct student{
    string id;
    string name;
    int score;
    student *link; // เก็บ address ของข้อมูลตัวถัดไป
};

// declare
student *data1;
student *data2;

// allocate memory
data1 = new student;
data2 = new student;
```

- การเชื่อมต่อ node ใน linked list

```cpp
data1->link = data2;
```

1.แทรกโหนดใหม่ เป็น node แรก

```cpp
p->link = data1;
first = p;
```

2.แทรกโหนดใหม่ เป็นโหนดสุดท้าย

```cpp
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

### Stack

**อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/13%20stack%20and%20queue.md) | [การบ้าน](/src/COS/COS2101/homework/13.cpp)

### ต้นไม้

- ฟังก์ชันแทรกโหนด ต้นไม้

**อ้างอิง:** [บรรยาย](/src/COS/COS2101/lecture/14%20tree.md)

```cpp

struct node
{
    node *llink;
    int data;
    node *rlink;
};

void insertTree(node *&root, int s)
{
    if (root == NULL)
    {
        root = new node;
        root->llink = NULL;
        root->data = s;
        root->rlink = NULL;
    }
    else if (s < root->data)
    {
        insertTree(root->llink, s);
    }
    else
    {
        insertTree(root->rlink, s);
    }
}

// usage
node *root = NULL;
insertTree(root, 74);
insertTree(root, 63);
insertTree(root, 92);
insertTree(root, 70);

```

- ฟังก์ชันแสดงโหนด ต้นไม้

```cpp
// postorder: root -> left -> right
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->llink);
        preOrder(root->rlink);
    }
}

// inorder: left -> root -> right
void inOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        inOrder(root->llink);
        cout << root->data << " ";
        inOrder(root->rlink);
    }
}

// preorder: left -> right -> root
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->llink);
        postOrder(root->rlink);
        cout << root->data << " ";
    }
}
```
