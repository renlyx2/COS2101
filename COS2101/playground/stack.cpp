#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct node
{
    char data;
    node *link;
};

void input(string &infix)
{
    cout << "Infix : ";
    cin >> infix;
}

int icp(char oparator)
{
    switch (oparator)
    {
    case '(':
        return 4;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case ')':
        return 1;
    }
    return 0;
}

int isp(node *top) // จะนำข้อมูลที่ ท๊อป ชี้อยู่มาหาลำดับความสำคัญ สังเกตุ ไม่มี &
{
    switch (top->data)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    }
    return 0;
}

void push(node *&top, char oparator)
{
    node *p;
    p = new node;
    p->data = oparator;
    p->link = NULL;

    if (top == NULL)
    {
        top = p; // แทรกโหนดใหม่เป็นโหนดแรก
    }
    else
    {
        p->link = top;
        top = p;
    }
}

void pop(node *&top, char &oparator)
{
    node *temp;
    if (top != NULL)
    {
        oparator = top->data;
        temp = top;
        top = top->link;
        delete (temp);
    }
    else
    {
        cout << "stack underflow";
    }
}

void process(string infix, string &postfix)
{
    node *top; // top data in stack
    top = NULL;
    int len = infix.length(); // total length of infix
    char oparator;
    for (int i = 0; i < len; i++)
    {
        if (
            (infix.at(i) >= 'A' && infix.at(i) <= 'Z') || (infix.at(i) >= 'a' && infix.at(i) <= 'z') || (infix.at(i) >= '0' && infix.at(i) <= '9'))
        {
            postfix += infix.at(i);
        }
        else if (
            top == NULL ||
            infix.at(i) == '(' ||
            icp(infix.at(i)) > isp(top))
        {
            push(top, infix.at(i));
        }
        else if (infix.at(i) == ')')
        {
            pop(top, oparator);
            while (oparator != '(')
            {
                postfix += oparator;
                pop(top, oparator);
            }
        }
        else
        { // case icp <= isp
            while (
                top != NULL && icp(infix.at(i)) <= isp(top))
            {
                pop(top, oparator);
                postfix += oparator;
            }
            push(top, infix.at(i));
        }
    } // end for
    // token all infix

    while (top != NULL)
    {
        pop(top, oparator);
        postfix += oparator;
    }
}

int main()
{
    string infix, postfix;
    infix = "(A+B)–(C*(D/E))+F";

    // input(infix);
    process(infix, postfix);

    cout << "postfix : " << postfix << endl;

    return 0;
}