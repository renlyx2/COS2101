#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// https://github.com/staciax2/cs-shared/blob/master/COS2101/13%20stack%20and%20queue.md#Queue

struct node
{
    string data;
    node *link;
};

struct resultNode
{
    float value;
    resultNode *link;
};

// struct postfixLinked{
//     string value;
//     postfixLinked *link;
// };

bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

void push(node *&top, string value)
{
    node *p = new node;
    p->data = value;
    p->link = NULL;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        p->link = top;
        top = p;
    }
}

void pop(node *&top, string &value)
{
    node *temp;
    if (top != NULL)
    {
        value = top->data;
        temp = top;
        top = top->link;
        delete (temp);
    }
    else
    {
        cout << "stack underflow" << endl;
    }
}

void pushResult(resultNode *&top, float value)
{
    resultNode *p = new resultNode;
    p->value = value;
    p->link = NULL;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        p->link = top;
        top = p;
    }
}

void popResult(resultNode *&top, float &value)
{
    resultNode *temp;
    if (top != NULL)
    {
        value = top->value;
        temp = top;
        top = top->link;
        delete (temp);
    }
    else
    {
        value = -1;
        // cout << "stack underflow" << endl;
    }
}

float calc(float &pre, float &post, char op)
{
    switch (op)
    {
    case '+':
        return pre + post;
    case '-':
        return pre - post;
    case '*':
        return pre * post;
    case '/':
        return pre / post;
    case '^':
        return pow(pre, post);
    default:
        return -1;
    }
}

void input(string &postfix)
{
    cout << "Enter postfix : ";
    cin >> postfix;
}

bool process(string &postfix, string &infix, float &result)
{
    // clear
    infix = "";
    result = 0.0;

    // declaration
    node *top = NULL;
    resultNode *resultTop = NULL;

    float pre = 0;
    float post = 0;
    int len = postfix.length();

    for (int i = 0; i < len; i++)
    {
        char post_at = postfix.at(i);
        if (isOperand(post_at))
        {
            push(top, string(1, post_at));
            pushResult(resultTop, stoi(string(1, post_at)));
        }
        else if (isOperator(post_at))
        {
            // result
            popResult(resultTop, post);
            popResult(resultTop, pre);
            if (pre != -1 && post != -1)
            {
                // cout << pre << post_at << post << endl;
                float r = calc(pre, post, post_at);
                if (r != -1)
                {
                    pushResult(resultTop, r);
                }
            }

            // oparand
            string op1 = "", op2 = "";
            pop(top, op1);
            pop(top, op2);
            push(top, "(" + op2 + post_at + op1 + ")");
        }
        else
        {
            result = -1;
            cout << "Invalid Operator at " << i << " is : " << post_at << endl;
            return false;
        }
    }

    while (top != NULL)
    {
        string temp = "";
        pop(top, temp);
        infix += temp + infix;
    }

    while (resultTop != NULL)
    {
        float result_expression;
        popResult(resultTop, result_expression);
        result += result_expression;
    }

    return true;
}

void display(string &infix, float &result)
{
    cout << "Infix expression: " << infix << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main()
{
    string postfix, infix = "";
    float result = 0;

    // TODO: maybe linklist postfix input

    input(postfix);
    while (postfix != "###")
    {
        if (process(postfix, infix, result))
        {
            display(infix, result);
        }
        input(postfix);
    }

    return 0;
}