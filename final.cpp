#include <iostream>
#include <cmath>

using namespace std;

class Complement {
public:
    int a[10], b[10], bit, result, complement1(int a[100], int bit), complement2(int a[100], int bit), plusMin(int b[100], int bit, int com);
    void input1(), input2(), menu();
} c;

void Complement::menu() {
    bool theEnd = false;
    early:
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
        input1();
        cout << "1's Complement ";
        complement1(a, bit);
        for (int i = 0; i < bit; i++) {
            cout << a[i];
        }
        cout << " : " << result << " -> 2's Complement ";
        complement2(a, bit);
        for (int i = 0; i < bit; i++) {
            cout << a[i];
        }
        cout << " : " << result << endl;
        break;

    case 2:
        input2();
        complement2(a, bit);
        temp = result;
        complement2(b, bit);
        temp += result;
        
        for (int i = 0; i < bit; i++) {
            cout << a[i];
        }

        cout << " " << complement2(a, bit) << " + ";

        for (int i = 0; i < bit; i++) {
            cout << b[i];
        }

        cout << " " << complement2(b, bit) << " = " << temp << endl
             << endl;
        break;

    case 3:
        input2();
        complement2(a, bit);
        temp = result;
        complement2(b, bit);
        temp -= result;
        for (int i = 0; i < bit; i++) {
            cout << a[i];
        }

        cout << " " << complement2(a, bit) << " - ";

        for (int i = 0; i < bit; i++) {
            cout << b[i];
        }

        cout << " " << complement2(b, bit) << " = " << temp << endl
             << endl;
        break;

    case 4:
        theEnd = true;
        break;

    default:
        break;
    }
    if (theEnd == false) {
        goto early;
    }

}

void Complement::input1() {
    cout << "Please input bit of biner : ";
    cin >> bit;
    string bin;
    cout << "Please enter the biner : " << endl;
    cin >> bin;
    string temp;
    for (int i = 0; i < bit; i++) {
        temp = bin[i];
        a[i] = stoi(temp);
    }
    system("clear");
}

void Complement::input2() {
    cout << "Please input bit of biner : ";
    cin >> bit;
    string bin1, temp1, bin2, temp2;
    cout << "Please enter the biner a: " << endl;
    cin >> bin1;
    for (int i = 0; i < bit; i++) {
        temp1 = bin1[i];
        a[i] = stoi(temp1);
    }
    system("clear");
    cout << "Please enter the biner b: " << endl;
    cin >> bin2;
    for (int i = 0; i < bit; i++) {
        temp2 = bin2[i];
        b[i] = stoi(temp2);
    }
    system("clear");
}

int Complement::complement1(int a[100], int bit) {
    result = 0;
    int value;
    if(bit == 1) {
        value = 1;
    } else if (bit > 1) {
        value = pow(2, bit - 1);
    }

    for (int i = 0; i < bit; i++) {
        if (i == 0 && a[0] == 1) {
            value -= 1;
            result -= value;
            value++;
        }
        else if (i != 0 && a[i] == 1) {
            result += value;
        }
        value /= 2;
    }
    return result;
}

int Complement::complement2(int a[100], int bit) {
    result = 0;
    int value;
    if(bit == 1) {
        value = 1;
    } else if (bit > 1) {
        value = pow(2, bit - 1);
    }

    for (int i = 0; i < bit; i++) {
        if (i == 0 && a[0] == 1)
        {
            result -= value;
        }
        else if (i != 0 && a[i] == 1)
        {
            result += value;
        }
        value /= 2;
    }
    if (result == -8) {
        result = 0;
    }
    return result;
}

int main() {
    c.menu();

    return 0;
}