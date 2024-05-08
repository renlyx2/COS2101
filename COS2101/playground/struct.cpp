#include <iostream>
#include <string>

using namespace std;

struct student
{
    int id;
    string name;
    int score;
    student *link;
};

void insert_first(student*&first) {
    student *n;
    n = new student;
    cout << "New Id:"; cin >> n->id;
    cout << "New Name:"; cin >> n->name;
    n->link = first;
    first = n;
}


int main()
{
    // ประกาศโหนด
    student *first;
    first = NULL;

    // แทรกโหนด
    int id;
    string name;
    float score = 0;

    cout << "ID: ";
    cin >> id;

    while (id != 0)
    {
        student *p;
        p = new student;

        cout << "name : ";
        cin >> name;
        cout << "Enter score : ";
        cin >> score;

        p->id = id;
        p->name = name;
        p->score = score;
        p->link = NULL;

        // คนแรก
        if (first == NULL)
        {
            first = p;
        }
        else // คนต่อๆ ไป
        {
            student *pre, *post;
            pre = NULL;
            post = first;

            // หาตำแหน่งที่จะแทรก
            while (post != NULL && p->id > post->id)
            {
                pre = post;
                post = post->link;
            }

            // แทรก
            if (pre == NULL) // แทรกตัวแรก
            {
                p->link = first;
                first = p;
            }
            else // แทรกหลังจาก pre และก่อน post
            {
                pre->link = p;
                p->link = post;
            } 
        }
        cout << "ID: ";
        cin >> id;
    }

    // ลบโหนด
    int del_id;

    // ข้อมูลที่จะลบ
    student *del;
    student *pre;

    pre = NULL;
    del = first;

    cout << "delete ID: ";
    cin >> del_id;

    // หาข้อมูลที่จะลบ ด้วยไอดี
    while (del != NULL && del->id != del_id)
    {
        pre = del;
        del = del->link;
    }

    // ข้อมูลก่อน ข้อมูลที่จะลบ ไม่พบ
    if (pre == NULL) // ลบตัวแรก
    {
        first = del->link;
        delete (del);
    }
    else if (del == NULL) // ไม่พบ
    {
        cout << "Not found" << endl;
    }
    else // ลบหลังจาก pre และก่อน del
    {
        pre->link = del->link;
        delete (del);
    }

    // display
    cout << "display" << endl;

    student *p;
    p = first;
    while (p != NULL)
    {
        cout << "ID: " << p->id << endl;
        cout << "Name: " << p->name << endl;
        cout << "Score: " << p->score << endl;
        if (p->link != NULL)
        {
            cout << "Link: " << p->link << endl;
        }
        else
        {
            cout << "Link: NULL" << endl;
        }
        cout << endl;
        p = p->link;
    }

    return 0;
}