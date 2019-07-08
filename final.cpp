#include <iostream>

using namespace std;

class Complement {
public:
    int a[10], b[10], bit, result, complement1(int a[100], int bit), complement2(int a[100], int bit), plusMin(int b[100], int bit, int com);
    void input1(), input2();
} c;

void Complement::input1() {
    cout << "Please input bit of biner : ";
    cin >> c.bit;
    string bin;
    cout << "Please enter the biner : " << endl;
    cin >> bin;
    string temp;
    for (int i = 0; i < c.bit; i++) {
        temp = bin[i];
        c.a[i] = stoi(temp);
    }
    system("clear");
}

void Complement::input2() {
    cout << "Please input bit of biner : ";
    cin >> c.bit;
    string bin1, temp1, bin2, temp2;
    cout << "Please enter the biner a: " << endl;
    cin >> bin1;
    for (int i = 0; i < c.bit; i++) {
        temp1 = bin1[i];
        c.a[i] = stoi(temp1);
    }
    system("clear");
    cout << "Please enter the biner b: " << endl;
    cin >> bin2;
    for (int i = 0; i < c.bit; i++) {
        temp2 = bin2[i];
        c.b[i] = stoi(temp2);
    }
    system("clear");
}

int Complement::complement1(int a[100], int bit) {
    c.result = 0;
    int value;
    if (c.bit == 4) {
        value = 8;
    }
    else if (c.bit == 5) {
        value = 16;
    }

    for (int i = 0; i < c.bit; i++) {
        if (i == 0 && a[0] == 1) {
            value -= 1;
            c.result -= value;
            value++;
        }
        else if (i != 0 && a[i] == 1) {
            c.result += value;
        }
        value /= 2;
    }
    return c.result;
}

int Complement::complement2(int a[100], int bit) {
    c.result = 0;
    int value;
    if (c.bit == 4) {
        value = 8;
    }
    else if (c.bit == 5) {
        value = 16;
    }

    for (int i = 0; i < c.bit; i++) {
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
    if (c.result == -8) {
        c.result = 0;
    }
    return c.result;
}

int main() {
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

    switch (choose) {
    case 1:
        c.input1();
        cout << "1's Complement ";
        c.complement1(c.a, c.bit);
        for (int i = 0; i < c.bit; i++) {
            cout << c.a[i];
        }
        cout << " : " << c.result << " -> 2's Complement ";
        c.complement2(c.a, c.bit);
        for (int i = 0; i < c.bit; i++) {
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

        for (int i = 0; i < c.bit; i++) {
            cout << c.a[i];
        }

        cout << " " << c.complement2(c.a, c.bit) << " + ";

        for (int i = 0; i < c.bit; i++) {
            cout << c.b[i];
        }

        cout << " " << c.complement2(c.b, c.bit) << " = " << temp << endl
             << endl;
        break;

    case 3:
        c.input2();
        cout << c.complement2(c.a, c.bit) << endl;
        temp = c.result;
        cout << c.complement2(c.b, c.bit) << endl;
        temp -= c.result;
        cout << c.result << endl;
        for (int i = 0; i < c.bit; i++) {
            cout << c.a[i];
        }

        cout << " " << c.complement2(c.a, c.bit) << " - ";

        for (int i = 0; i < c.bit; i++) {
            cout << c.b[i];
        }

        cout << " " << c.complement2(c.b, c.bit) << " = " << temp << endl
             << endl;
        break;

    case 4:
        return 0;

    default:
        break;
    }
    goto awal;
}