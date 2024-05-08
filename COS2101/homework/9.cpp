#include <iostream>
#include <string>
// #include <iomanip>

using namespace std;

// 1

void input1(int x[5][5], int &n, int grade[], int &sum)
{
    // do
    // {
    //     cout << "Enter number of student: (0-25): ";
    //     cin >> n;
    // } while (n < 0 || n > 25);

    int temp;
    bool is_continue = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            do
            {
                cout << "Enter score for student at " << n + 1 << ": ";
                cin >> temp;
            } while ((temp < 0 || temp > 100) && temp != -999);
            if (temp == -999)
            {
                is_continue = false;
                break;
            }
            sum += temp;
            if (temp >= 80)
            {
                grade[0] += 1;
            }
            else if (temp >= 60)
            {
                grade[1] += 1;
            }
            else
            {
                grade[2] += 1;
            }

            n++;
            // if (count == n)
            // {
            //     temp = -999;
            //     break;
            // }
        }
        if (!is_continue)
        {
            break;
        }
    }
}

void output(const int score[5][5], float &avg, const int grade[])
{
    cout << "average score is " << avg << endl;
    cout << "Student grade is G = " << grade[0] << endl;
    cout << "Student grade is P =" << grade[1] << endl;
    cout << "Student grade is F = " << grade[2] << endl;
}

void one()
{
    int n = 0;
    int sum = 0;
    int score[5][5] = {0};
    int grade[3] = {0};
    float avg = 0;

    input1(score, n, grade, sum);
    if (n == 0)
    {
        avg = 0;
    }
    output(score, avg, grade);
}

// 2

void input2(int month[4][3], string name[3], int sale[3])
{
    string mouth_name[3] = {"Apr", "May", "Jun"};
    for (int i = 0; i < 4; i++)
    {
        int m_index = 0;
        for (int j = 0; j < 3; j++)
        {
            do
            {
                cout << "Enter employee "
                     << "'" << name[i] << "'"
                     << " at month " << mouth_name[m_index] << ": ";
                cin >> month[i][j];
            } while (month[i][j] < 0);
            sale[i] += month[i][j];
            m_index++;
        }
        cout << endl;
    }
}

void output2(const int month[4][3], const string name[3], const int sale[3])
{
    int max_index = 1;
    for (int i = 0; i < 4; i++)
    {
        int bonus = 1;
        if (sale[i] >= 100)
        {
            bonus = 8;
        }
        else if (sale[i] >= 80)
        {
            bonus = 5;
        }
        else if (sale[i] >= 50)
        {
            bonus = 3;
        }
        if (sale[i] > sale[max_index])
        {
            max_index = i;
        }
        cout << name[i] << " total sale is " << sale[i] << endl;
        cout << name[i] << " get " << bonus << " month bonus" << endl;
        cout << endl;
    }
    cout << name[max_index] << " is the best employee" << endl;
}

void two()
{
    int employee_month[4][3] = {0};
    string employee_name[4] = {"NOK", "MEOW", "MAM", "KAT"};
    int employee_sale[3] = {0};

    input2(employee_month, employee_name, employee_sale);
    output2(employee_month, employee_name, employee_sale);
}

// main

int main()
{
    // one();
    two();
    return 0;
}