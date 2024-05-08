#include <iostream>

using namespace std;

struct student
{
    int id;
    string name;
    float score;
    student *link;
};

void setData(student *p, int id, string name, float score, student *link = NULL)
{
    p->id = id;
    p->name = name;
    p->score = score;
    p->link = link;
}

int main()
{
    student *students, *pre, *post;

    int id;
    string name;
    float score = 20;
    cout << "ID: ";
    cin >> id;

    while (id != 0)
    {
        student *p;
        p = new student;

        cout << "name : ";
        cin >> name;

        setData(p, id, name, score);

        p->link = NULL;
        if (students == NULL)
        {
            students = p;
        }
        else
        {
            pre = NULL;
            post = students;
            while (post != NULL && post->id < p->id)
            {
                pre = post;
                post = post->link;
            }
            if (pre == NULL)
            {
                p->link = students;
                students = p;
            }
            else
            {
                pre->link = p;
                p->link = post;
            }
        }
        cout << "ID: ";
        cin >> id;
    }

    cout << "____________________________" << endl;

    student *p;
    p = students;
    while (p != NULL && p->link != NULL)
    {
        cout << "ID: " << p->id << endl;
        cout << "Name: " << p->name << endl;
        cout << "Score: " << p->score << endl;
        cout << "Link: " << p->link << endl;
        cout << endl;
        p = p->link;
    }

    cout << "____________________________" << endl;

    // delete data by id

    student *del, *pre2;
    pre2 = NULL;
    del = students;

    int del_id = 2;

    // หาข้อมูลที่จะลบ ด้วยไอดี
    while (del != NULL && del->id != del_id)
    {
        pre2 = del;
        del = del->link;
    }

    // ข้อมูลก่อน ข้อมูลที่จะลบ ไม่พบ
    if (pre2 == NULL)
    {
        students = del->link;
        delete del;
    }

    else if (del == NULL)
    {
        cout << "Not found" << endl;
    }
    else
    {
        pre2->link = del->link;
        delete del;
    }

    student *pa;
    pa = students;
    while (pa != NULL && pa->link != NULL)
    {
        cout << "ID: " << pa->id << endl;
        cout << "Name: " << pa->name << endl;
        cout << "Score: " << pa->score << endl;
        cout << "Link: " << pa->link << endl;
        cout << endl;
        pa = pa->link;
    }

    cout << "____________________________" << endl;

    return 0;
}