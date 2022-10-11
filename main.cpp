#include <iostream>
#include <algorithm>

using namespace std;
//	Добавить возможность изменить произвольные биты на 1 или 0 по указанию пользователя.
void change(int input){
    const int count = 8 * sizeof(int) - 1;
    cout << "Enter the bit and bit number you want to replace (separated by a space): ";
    int index,value;
    int mask;
    cin >> value >> index;
    if (value==1){
        mask = 1 << (index-1);
        input |= mask;
    }else if (value==0){
        mask = 1 << (index-1);
        mask = ~mask;
        input &= mask;
    }else {
        cout << "ERROR!!!";
    }
    for (int i = 0; i <= count; i++) {
        if (i == 1 || (i % 8 == 0 and i != 0)) {
            putchar(' ');
        }
        mask = 1 << (count - i);
        putchar(input & mask ? '1' : '0');
    }
}

int main(){
    const int count = 8 * sizeof(int) - 1;
    int contin = 1;
    while (contin == 1) {
        //1. Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без.
        cout << "|int:" << sizeof(int) << "\n|int short: " << sizeof(int short) << "\n|long int: " << sizeof(long int);
        cout << "\n|float: " << sizeof(float) << "\n|double: " << sizeof(double) << "\n|long double: "
             << sizeof(long double);
        cout << "\n|char: " << sizeof(char) << "\n|bool: " << sizeof(bool);
        //2. Вывести на экран двоичное представление в памяти (все разряды) целого числа.
        int inputInt;
        cout << "\n" << "Enter an integer number(integer): ";
        try {
            cin >> inputInt;
            if (cin.fail()) {
                throw 1;
            }
        } catch (int exeption) {
            cout << "ERROR!!!";
            exit(0);
        }
        cin.sync();
        int mask;
        for (int i = 0; i <= count; i++) {
            if (i == 1 || (i % 8 == 0 and i != 0)) {
                putchar(' ');
            }
            mask = 1 << (count - i);
            putchar(inputInt & mask ? '1' : '0');
        }
        cout << "\n";
        change(inputInt);

        // 3 Вывести на экран двоичное представление в памяти (все разряды) типа float.

        union {
            float inputFloat;
            int equalFloat;
        };
        cout << "\n" << "Enter a fractional number(float): ";
        try {
            cin >> inputFloat;
            if (cin.fail()) {
                throw 1;
            }
        } catch (int exeption) {
            cout << "ERROR!!!";
            exit(0);
        }
        cin.sync();
        for (int i = 0; i <= count; i++) {
            if (i == 1 || i == 9) {
                putchar(' ');
            }
            mask = 1 << (count - i);
            putchar(equalFloat & mask ? '1' : '0');
        }
        //4 Вывести на экран двоичное представление в памяти (все разряды) типа double.

        union {
            int arr[2];
            double inputDouble;
        };
        cout << "\n" << "Enter a fractional number(double): ";
        try {
            cin >> inputDouble;
            if (cin.fail()) {
                throw 1;
            }
        } catch (int exeption) {
            cout << "ERROR!!!";
            exit(0);
        }
        cin.sync();
        for (int i = 1; i >= 0; i--) {
            for (int j = 0; j <= count; j++) {
                if ((j == 1 || j == 12) && i == 1) {
                    putchar(' ');
                }
                mask = 1 << (count - j);
                putchar(arr[i] & mask ? '1' : '0');
            }
        }
        cout << "\n" << "If you want to run the program again press 1: ";
        cin >> contin;
    }
    return 0;
}
