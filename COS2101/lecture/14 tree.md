# Tree ต้นไม้

โครงสร้างต้นไม้ `non-linear` เก็บในรูปลำดับชั้น

โหนดของต้นไม้ มีลักษณะดังนี้:

1. `root node` โหนดราก อยู่บนสุดของต้นไม้
2. โหนดสามารถแบ่งเป็นต้นไม้ย่อยๆ `subtree` ได้ แต่ละ `subtree` จะมีโหนดรากของตัวเอง

```bash
     v1
    /  \
   v2   v3
  /  \    \
 v4  v5    v6
```

ต้นไม้ ย่อย ของ **`v1`** ได้แก่ `{v2, v5, v6}`, `{v2}`, `{v4}`

**`v1`** คือ root node \
**`v4`** คือ leaf node (ใบ) ไม่มีโหนดย่อย? \
**`v2`** คือ กิ่ง (branch) มีโหนดย่อย

**depth** คือ ระดับของโหนด โดย \
**`root node`** มี depth `0` \
**`v2`** มี depth `1` \
**`v5`** มี depth `2`

### ชนิดของต้นไม้

1. `ordered tree` ลำดับของโหนดมีความสำคัญ
2. `orantad tree` ลำดับของโหนดไม่มีความสำคัญ

```bash
    a
   b c
      d e

     a
   c   b
  d e

note: เดี่ยวมาแก้
```

### ต้นไม้แบบทวิภาค (binary tree)

- เป็นชนิด ordered tree มีกิ่ง (outnode) ของทุกๆ โหนด น้อยกว่าเท่ากับ 2

ใน กรณีที่ outnode มีค่า 2 หรือ 0 เท่านั่น

**binary tree**

```bash
     a
    /  \
  b     c
 /     / \
i     d   e
```

**full binary tree**

```bash
     a
   /   \
  b      c
 / \    / \
i   j  d   e
```

<!-- /  \ -->

1.ป้อนข้อมูลคะแนนของ นศ n คน เก็บในโครงสร้างต้นไม้, ลบข้อมูลนศ
ในโครงสร้างต้นไม้ม พิมพ์ข้อมูลทั่งหมด

**ป้อน** `50` `60` `70` `80` `90` `-1`

- ต้นไม้แบบทวิภาค ค้นหาโดย binary search tree

**เงื่อนไข**

1. ข้อมูลของ `left subtree` น้อยกว่า `root node` ทุกโหนด
2. ข้อมูล `right subtree` มากกว่า `root node` ทุกโหนด
   input: 50 60 45 80 90

```bash
    50
   /  \
  45   60
      /  \
    80    90
```

| l-link | data | r-link |
| ------ | ---- | ------ |
| null   | 50   | null   |
| null   | null | 60     |
| 45     | null | null   |
| null   | null | 80     |
| null   | null | 90     |

วาดรูปต้นไม้
input: `74` `63` `92` `54` `23` `45`

```bash
    74
  63   92
54
23
    45

note: เดี่ยวมาแก้
```

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
int main(){
    node *root = NULL;
    insertTree(root, 74);
    insertTree(root, 63);
    insertTree(root, 92);
    insertTree(root, 70);
    return 0;
}
```

### การแวะผ่านต้นไม้ (traveling tree)

1. pre-order : root -> left -> right
2. in-order : left -> root -> right
3. post-order: left -> right -> root

**พิจารณา ต้นไม้**

```bash
     50
    /  \
   30   80
```

**pre-order:** 50 30 80 \
**in-order:** 30 50 80 `(เรียงลำดับ น้อยไปมาก)` \
**post-order:** 30 80 50

**พิจารณา ต้นไม้**

```bash
     50
    /  \
  30    80
  /    /  \
20    70  85
```

**pre-order:** 50 30 null 20 80 70 85 \
**in-order:** 20 30 null 50 70 80 85 \
**post-order:** 20 null 30 70 85 80 50

### งาน

1. สร้างต้นไม้จาก 60 50 40 75 85 65 70
   ให้ท่อง `pre-order`, `in-order`, `post-order`

```bash
      60
    /    \
  50      75
 /       /  \
40      65   85
       /
      70
```

**pre-order:** 60 50 40 75 65 70 85 \
**in-order:** 40 50 60 65 70 75 85 \
**post-order:** 40 50 70 65 85 75 60

```cpp

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->llink);
        preOrder(root->rlink);
    }
}

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

### การลบโหนดของต้นไม้

```bash
         60
       /    \
     50      70
    /  \    /  \
  20   55  65   80
  /               \
10                90
```

- ถ้าต้องการลบโหนด **60** \
   หาโหนดที่มาที่สุดของ `left subtree` นำมาแทนที่และลบโหนดที่แทนที่ \
   หาโหนดที่มาที่น้อยที่สุดของ `right subtree`นำมาแทนที่และลบโหนดที่แทนที่

- ต้องการลบโหนด **20** \
  มีเฉพาะ `left subtree` นำ `left subtree` มาแทนโหนดที่ต้องการลบเลย

- ต้องการลบโหนด **80** \
  มีเฉพาะ `right subtree` นำ `right subtree` มาแทนโหนดที่ต้องการลบเลย

```cpp
void deleteTree(node *&root, int delData)
{
    if (root == NULL)
    {
        cout << "not found" << endl;
    }
    else if (delData < root->data)
    {
        deleteTree(root->llink, delData);
    }
    else if (delData > root->data)
    {
        deleteTree(root->rlink, delData);
    }
    else // พบโหนดที่ต้องการลบ
    {
        if (root->llink == NULL)
        {
            // root = root->llink;
            // deleteTree(root->llink, root->data);
            root->data = root->rlink->data;
            deleteTree(root->rlink, root->data);
        }
        else if (root->rlink == NULL)
        {
            root->data = root->rlink->data;
            deleteTree(root->rlink, root->data);
        }
        else
        {
            // มีทั่ง left และ right subtree
            node *temp = findMin(root->rlink); // หาโหนดที่มาที่น้อยที่สุดของ right subtree
            root->data = temp->data;
            // delete(root->rlink, root->data);
            deleteTree(root->rlink, root->data);
        }
    }
}
```

# การประยุกต์ใช้งาน ต้นไม้

แทนนิพจน์ทางคณิตศาสตร์

**infix:** `A+B*C-D/E` \
**postfix:** `ABC*+DE/-` \
แทนนิพจน์นี้โดยใช้โครงสร้าต้นไม้
โดย \
`ราก` เก็บ `operator` \
`ใบ` เก็บ `operand`

`ABC*+DE/-`

1. ถ้าเป็น operand จะสร้างโหนด และ ทำการ push เข้า stack \
   `A` push \
   `B` push \
   `C` push

2. ถ้าเป็น operator จะให้เป็นรากของต้นไม้ย่อย โดย pop ครั่งที่ 1 นำไปเชื่อมกับ left subtree และ pop ครั่งที่ 2 push ต้นไม้ย่อยลง stack

```bash
         +
       /   \
     +       -
    / \     /  \
   A   *   D    E
       / \
      B   C
```
