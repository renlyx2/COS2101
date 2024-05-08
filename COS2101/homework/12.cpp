#include <iostream>

using namespace std;

struct student
{
    int id;
    string name;
    float score;
    student *link;
};

void setData(student *p, int id, string name, float score)
{
    p->id = id;
    p->name = name;
    p->score = score;
    p->link = NULL;
}

int main()
{
    // สร้างตัวแปร student
    student *student_1;
    student *student_2;
    student *student_3;
    student *student_4;

    // ร้องขอข้อมูล ไปยัง memory
    student_1 = new student;
    student_2 = new student;
    student_3 = new student;
    student_4 = new student;

    // กำหนดข้อมูล

    setData(student_1, 1, "A", 1.0);
    setData(student_2, 2, "B", 2.0);
    setData(student_3, 3, "C", 3.0);
    setData(student_4, 4, "D", 4.0);

    // เชื่อมต่อข้อมูล

    student_1->link = student_2;
    student_2->link = student_3;
    student_3->link = student_4;
    student_4->link = NULL;

    // เตรียมลบข้อมูล

    student *del;
    student *pre;

    pre = NULL;
    del = student_1;

    // รับไอดีที่จะลบ

    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    // หาข้อมูลที่จะลบ ด้วยไอดี
    while (del != NULL && del->id != id)
    {
        pre = del;
        del = del->link;
    }

    // ข้อมูลก่อน ข้อมูลที่จะลบ ไม่พบ
    if (pre == NULL)
    {
        student_1 = del->link;
        delete del;
    }

    else if (del == NULL)
    { // กรณีไม่พบข้อมูลที่จะลบ
        cout << "Not found" << endl;
    }
    else
    { // กรณีพบข้อมูลที่จะลบ
        pre->link = del->link;
        delete del;
    }

    // แสดงข้อมูล

    student *p;
    p = student_1;
    while (p != NULL)
    {
        cout << p->id << " " << p->name << " " << p->score << endl;
        p = p->link;
    }

    return 0;
}