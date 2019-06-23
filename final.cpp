#include <iostream>

using namespace std;

class Complement
{
public:
    int a[10], b[10], bit, result, complement1(int a[100], int bit), complement2(int a[100], int bit), plusMin(int b[100], int bit, int com);
    void input1(), input2();
} c;

void Complement::input1()
{
    cout << "Please input bit of biner : ";
    cin >> c.bit;
    cout << "Please enter the biner : " << endl;
    for (int i = 0; i < c.bit; i++)
    {
        cin >> c.a[i];
    }
    system("clear");
}

void Complement::input2()
{
    cout << "Please enter the biner a: " << endl;
    for (int i = 0; i < c.bit; i++)
    {
        cin >> c.a[i];
    }
    system("clear");
    cout << "Please enter the biner b: " << endl;
    for (int i = 0; i < c.bit; i++)
    {
        cin >> c.b[i];
    }
    system("clear");
}

int Complement::complement1(int a[100], int bit)
{
    c.result = 0;
    int value;
    if (c.bit == 4)
    {
        value = 8;
    }
    else if (c.bit == 5)
    {
        value = 16;
    }

    for (int i = 0; i < c.bit; i++)
    {
        if (i == 0 && a[0] == 1)
        {
            value -= 1;
            c.result -= value;
            value++;
        }
        else if (i != 0 && a[i] == 1)
        {
            c.result += value;
        }
        value /= 2;
    }
    return c.result;
}

int Complement::complement2(int a[100], int bit)
{
    c.result = 0;
    int value;
    if (c.bit == 4)
    {
        value = 8;
    }
    else if (c.bit == 5)
    {
        value = 16;
    }

    for (int i = 0; i < c.bit; i++)
    {
        if (i == 0 && a[0] == 1)
        {
            c.result -= value;
        }
        else if (i != 0 && a[i] == 1)
        {
            c.result += value;
        }
        value /= 2;
    }
    return c.result;
}

int Complement::plusMin(int b[100], int bit, int com)
{
    int value;
    if (c.bit == 4)
    {
        value = 8;
    }
    else if (c.bit == 5)
    {
        value = 16;
    }
    if (c.b[0] == 0)
    {
        value *= -1;
        c.b[0] = 1;
    }
    else if (c.b[0] == 1)
    {
        c.b[0] = 0;
    }

    if (com < 0)
    {
        int i = 1;
        while (1)
        {
            if ((value - c.b[i] < 0))
            {
                c.b[i] = 0;
            }
            else
            {
                value -= c.b[i];
            }
            if (value == 0)
            {
                break;
            }
            i++;
        }
    }

    return 1;
}

int main()
{
awal:
    int choose, temp = 0;
    cout << "Choose menu : " << endl;
    cout << "1. 1's Complement to 2.s Complement" << endl;
    cout << "2. Addition of 2 Biner" << endl;
    cout << "3. Substraction of 2 Biner" << endl;
    cout << "4. Exit" << endl;
    cout << "Please : ";
    cin >> choose;
    system("clear");

    switch (choose)
    {
    case 1:
        c.input1();
        cout << "1's Complement ";
        c.complement1(c.a, c.bit);
        for (int i = 0; i < c.bit; i++)
        {
            cout << c.a[i];
        }
        cout << " : " << c.result << " -> 2's Complement ";
        c.complement2(c.a, c.bit);
        for (int i = 0; i < c.bit; i++)
        {
            cout << c.a[i];
        }
        cout << " : " << c.result << endl;
        break;

    case 2:
        c.input2();
        c.complement2(c.a, c.bit);
        temp = c.result;
        c.complement2(c.b, c.bit);
        temp += c.result;

        for (int i = 0; i < c.bit; i++)
        {
            cout << c.a[i];
        }

        cout << " " << c.result << " + ";

        for (int i = 0; i < c.bit; i++)
        {
            cout << c.b[i];
        }

        cout << " " << c.result << " = " << temp << endl
            << endl;
        break;

    case 3:
        c.input2();
        c.complement2(c.a, c.bit);
        temp = c.result;
        c.complement2(c.b, c.bit);
        temp -= c.result;
        c.plusMin(c.b, c.bit, c.result);
        for (int i = 0; i < c.bit; i++)
        {
            cout << c.a[i];
        }

        cout << " " << c.result << " + ";

        for (int i = 0; i < c.bit; i++)
        {
            cout << c.b[i];
        }

        cout << " " << c.result << " = " << temp << endl << endl;
        break;

    case 4:
        return 0;

    default:
        break;
    }
    goto awal;
}