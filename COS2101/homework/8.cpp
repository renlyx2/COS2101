#include <iostream>
#include <cmath>

using namespace std;

// A U B
void FindUnion(const int x[], const int y[], int size_x, int size_y, int ar_union[])
{
    int size = 0;
    for (int i = 0; i < size_x; i++)
    {
        ar_union[size] = x[i];
        size++;
    }
    for (int j = 0; j < size_y; j++)
    {
        bool is_duplicate = false;
        for (int i = 0; i < size_x; i++)
        {
            if (y[j] == x[i])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            ar_union[size] = y[j];
            size++;
        }
    }
}

// A - B
void FindDiff(const int x[], const int y[], int size_x, int size_y, int ar_diff[])
{
    for (int i = 0; i < size_x; i++)
    {
        bool is_duplicate = false;
        for (int j = 0; j < size_y; j++)
        {
            if (x[i] == y[j])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            ar_diff[i] = x[i];
        }
    }
}

// A n B
void FindInter(int x[], int y[], int size_x, int size_y, int ar_inter[])
{
    int size = 0;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (x[i] == y[j])
            {
                ar_inter[size] = x[i];
                size++;
            }
        }
    }
}

void output(int ar_u[], int ar_d[], int ar_i[], int size)
{
    cout << "A U B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_u[i] > 0)
        {
            cout << ar_u[i];
            if (ar_u[i + 1] != 0)
            {
                cout << ", ";
            }
        }
    }
    cout << "}";
    cout << endl;

    cout << "A - B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_d[i] > 0)
        {
            cout << ar_d[i];
            cout << ", ";
        }
    }
    cout << "}";
    cout << endl;

    cout << "A Inter B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_i[i] > 0)
        {
            cout << ar_i[i];
            cout << ", ";
        }
    }
    cout << "}";
    cout << endl;
}

void one()
{
    int a, b;

    cout << "Input Size of setA : ";
    cin >> a;

    int A[a] = {0};
    for (int i = 0; i < a; i++)
    {
        cout << "satA index at " << i + 1 << " : ";
        cin >> A[i];
    }
    cout << "Input Size of setB : ";
    cin >> b;

    int B[b] = {0};
    for (int i = 0; i < b; i++)
    {
        cout << "satB i index at " << i + 1 << " : ";
        cin >> B[i];
    }

    int sizeA = a;              // 4
    int sizeB = b;              // 4
    int sizeAB = sizeA + sizeB; // 4 + 4 = 8

    int AUB[sizeAB] = {0}; // UNION
    int ADB[sizeAB] = {0}; // DIFF
    int AIB[sizeAB] = {0}; // INTER

    FindUnion(A, B, sizeA, sizeB, AUB);
    FindDiff(A, B, sizeA, sizeB, ADB);
    FindInter(A, B, sizeA, sizeB, AIB);
    output(AUB, ADB, AIB, sizeAB);
}

// 2

void input2(float ar[], int &index, float &insert)
{
    int size = 0;
    for (int i = 0; i < 20; i++)
    {
        do
        {
            cout << "Input Number at " << i + 1 << " : ";
            cin >> ar[i];
        } while (ar[i] <= 0 && ar[i] != -999);
        if (ar[i] == (-999))
        {
            ar[i] = 0;
            break;
        }
        size++;
    }
    do
    {
        cout << "Index to insert: ";
        cin >> index;
    } while (index > size);

    do
    {
        cout << "insert data: ";
        cin >> insert;
    } while (insert < 0);
}

void process2(float ar[], int &index, float &insert)
{
    int temp = 0.0, before = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (i == index)
        {
            temp = ar[i];
            ar[i] = insert;
        }
        else if (i > index)
        {
            before = ar[i];
            ar[i] = temp;
            temp = before;
        }
    }
}

void display2(float ar[])
{
    cout << "Array = {";
    for (int i = 0; i < 100; i++)
    {
        if (ar[i] != 0)
        {
            cout << ar[i];
            if (ar[i + 1] != 0)
            {
                cout << ", ";
            }
        }
    }
    cout << "}";
}

void two()
{
    float ar[100] = {0};
    int index = 0;
    float insert = 0;
    input2(ar, index, insert);
    process2(ar, index, insert);
    display2(ar);
}

void input3(int &n)
{
    cout << endl;
    cout << "Input n : ";
    cin >> n;
    // n = 6;
}

void inputArray(int ar[], int &n, float &sum)
{
    int v = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Input index at " << i << ": ";
        cin >> ar[i];
        if (ar[i] != -999)
        {
            v++;
            sum += ar[i];
        }
        else
        {
            break;
        }
    }
}

float process3(const int ar[], int &n, float mean)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] != -999)
        {
            sum += pow((ar[i] - mean), 2);
        }
        else
        {
            break;
        }
    }
    return sqrt(sum / (n - 1));
}

void output3(float sum)
{
    cout << "variance is " << sum << endl;
}

void three()
{
    float mean = 0;
    int n = 0;
    input3(n);
    int ar[n] = {0};
    inputArray(ar, n, mean);
    cout << "mean is " << mean / n << endl;
    output3(process3(ar, n, mean / n));
}

int main()
{
    // one();
    // cout << endl;
    two();
    cout << endl;
    // three();
    return 0;
}