#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    cout << " Calculation of expressions using bitwise operations  \n";
        int a, b, c, d;
        int ABCD, ACDB;
        cout << "ACDB = (127 * a + 32 * c) / 4096 - d * 1200 + b * 131" << endl;
        cout << "Enter a" << endl;
        cin >> a;

        cout << "Enter b" << endl;
        cin >> b;

        cout << "Enter c" << endl;
        cin >> c;

        cout << "Enter d" << endl;
        cin >> d;

        ACDB = (127 * a + 32 * c) / 4096 - d * 1200 + b * 131;
        ABCD = (((a << 7) - a + (c << 5)) >> 12) - (d << 10) - (d << 7) - (d << 5) - (d << 4) + (b << 7) + (b << 1) + b;

        cout << "RES" << endl;   
        cout << ACDB << endl;
        cout << ABCD << endl;
        _getch();
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


