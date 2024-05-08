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

void sort_item(student *students, int size)
{
    bool swapped = true;
    student *pre, *post, *temp;
    pre = NULL;
    post = students;

    // students->link != NULL &&
    while (swapped)
    {
        swapped = false;
        if (pre == NULL)
        {
            pre = post;
        }
        if (pre->id > pre->link->id)
        {
            temp = pre;
            pre = pre->link;
            pre->link = temp;
            swapped = true;
        }
    }
}

// for (int i = 0; i < (size - 1); i++)
// {
//     if (item[i].id > item[i + 1].id)
//     {
//         temp = item[i];
//         item[i] = item[i + 1];
//         item[i + 1] = temp;
//         swapped = true;
//     }
// }

void sort_item2(student *students, int size)
{
    bool swapped = true;
    student *temp;
    while (swapped)
    {
        swapped = false;
        student *p;
        p = students;
        while (p != NULL)
        {
            if (p->id > p->link->id)
            {
                temp = p;
                p = p->link;
                p->link = temp;
                swapped = true;
            }
            p = p->link;
        }
    }
}

int main()
{
    student *students, *last;

    int i = 10;
    int id;

    students = new student;
    setData(students, i, "A", 1.0);
    last = students;

    while (i > 1)
    {
        i--;
        student *p;
        p = new student;

        // cin
        setData(p, i, "A", 1.0);

        while (last->link != NULL)
        {
            last = last->link;
        }
        last->link = p;
    }

    // while (i > 5)
    // {

    //     student *p;
    //     p = new student;
    //     setData(students, i, "A", 1.0);
    //     while (last->link != NULL)
    //     {
    //         last = last->link;
    //     }
    //     last->link = p;
    //     i++;
    // }

    sort_item2(students, 10);

    student *p;
    p = students;
    while (p != NULL)
    {
        cout << "ID: " << p->id << endl;
        cout << "Name: " << p->name << endl;
        cout << "Score: " << p->score << endl;
        cout << "Link: " << p->link << endl;
        cout << endl;
        p = p->link;
    }

    return 0;
}