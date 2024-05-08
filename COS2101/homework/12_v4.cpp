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

void delStudent(student *&students, int del_id)
{
    student *del, *pre;
    pre = NULL;
    del = students;

    // หาข้อมูลที่จะลบ ด้วยไอดี
    while (del != NULL && del->id != del_id)
    {
        pre = del;
        del = del->link;
    }

    // ข้อมูลก่อน ข้อมูลที่จะลบ ไม่พบ
    if (pre == NULL)
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
        pre->link = del->link;
        delete del;
    }
}

void display(const student *p)
{
    while (p != NULL && p->link != NULL)
    {
        cout << "ID: " << p->id << endl;
        cout << "Name: " << p->name << endl;
        cout << "Score: " << p->score << endl;
        if (p->link != NULL)
        {
            cout << "Link: " << p->link << endl;
        }
        cout << endl;
        p = p->link;
    }
}

void insertStudent(student *&students)
{
    student *pre, *post;
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
        p->link = NULL; // กันเหนียว

        // คนแรก
        if (students == NULL)
        {
            students = p;
        }
        else // คนต่อๆ ไป
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
}

int main()
{
    student *students;
    int del_id;

    // insert
    insertStudent(students);

    cout << "____________________________" << endl;

    // display
    display(students);

    cout << "____________________________" << endl;

    // delete

    cout << "Enter Student ID to delete : ";
    cin >> del_id;

    while (del_id != -999)
    {
        delStudent(students, del_id);
        display(students);
        cout << endl;
        cout << "Enter Student ID to delete : ";
        cin >> del_id;
        cout << endl;
    }

    cout << endl;

    // display
    display(students);

    cout << "____________________________" << endl;

    return 0;
}