#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define SHORT_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define SHORT_TO_BINARY(short)  \
  (short & 0x8000 ? '1' : '0'), \
  (short & 0x4000 ? '1' : '0'), \
  (short & 0x2000 ? '1' : '0'), \
  (short & 0x1000 ? '1' : '0'), \
  (short & 0x0800 ? '1' : '0'), \
  (short & 0x0400 ? '1' : '0'), \
  (short & 0x0200 ? '1' : '0'), \
  (short & 0x0100 ? '1' : '0'), \
  (short & 0x80 ? '1' : '0'), \
  (short & 0x40 ? '1' : '0'), \
  (short & 0x20 ? '1' : '0'), \
  (short & 0x10 ? '1' : '0'), \
  (short & 0x08 ? '1' : '0'), \
  (short & 0x04 ? '1' : '0'), \
  (short & 0x02 ? '1' : '0'), \
  (short & 0x01 ? '1' : '0') 

unsigned char parbit(unsigned char c)
{
	unsigned char t = 1, b = 0;
	for (int j = 0; j < 8; j++)         // обчислення біта парності
	{
		if (c & t) {
			if (b == 0) b = 1; else b = 0;
		}
		t <<= 1;
	}
	return b;
}

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

void WriteArrayBinFile(int n, unsigned short* arr)
{
	char fileName[200];
	cout << "Input Filename:\n";
	cin >> fileName;

	//ios_base
	ofstream bfout(fileName, ios_base::binary);
	if (bfout.fail()) return;
	bfout.write((const char*)&n, sizeof(int));
	std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(unsigned short);
	bfout.write((const char*)arr, cn);
	bfout.close();
}

int ReadArrayBinFile(int n, unsigned short* arr)
{
	char fileName[200];
	cout << "Input Filename:\n";
	cin >> fileName;

	int size = 0;
	ifstream bfin(fileName, ios_base::binary);
	if (bfin.fail()) return 0;
	bfin.read((char*)&size, sizeof(int));
	if (size <= 0) return 0;
	if (size > n) size = n;
	bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(unsigned short));
	bfin.close();
	// ssdhs
	return size;
}

void encript()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

	char S[8][8];
	unsigned short encripted[64];
	unsigned char i, j;
	 

	for (i = 0; i < 8; i++) {
		cout << " Input string (size <=8) \n";
		cin.get(S[i], 8);
		cin.get();
	}

	for (i = 0; i < 8; i++) {
		cout << S[i] << '\n';
	}

	for (i = 0; i < 8; i++) {
		int n = strlen(S[i]);
		for (j = n; j < 8; j++) {
			S[i][j] = ' ';
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << S[i][j] << '|';
		}
		cout << endl;
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf(BYTE_TO_BINARY_PATTERN" | ", BYTE_TO_BINARY(S[i][j]));
		}
		cout << endl;
	}
	unsigned char tmp, tmp2, byte1, byte2;
	char tmpChar;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {

			byte1 = 0;
			tmp = i;
			tmp = tmp << 5;
			byte1 = byte1 | tmp;
			tmp = S[i][j] << 4;
			tmp = tmp >> 3;
			byte1 = byte1 | tmp;
			byte1 = byte1 | parbit(byte1);

			byte2 = 0;
			tmp2 = j;
			tmp2 = tmp2 << 1;
			byte2 = byte2 | tmp2;

			tmp2 = S[i][j] >> 4;
			tmp2 = tmp2 << 4;
			byte2 = byte2 | tmp2;
			byte2 = byte2 | parbit(byte2);


			encripted[i * 8 + j] = byte1;
			encripted[i * 8 + j] = (encripted[i * 8 + j] << 8) | byte2;
		}
		cout << endl;
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf(SHORT_TO_BINARY_PATTERN" | ", SHORT_TO_BINARY(encripted[i * 8 + j]));
		}
		cout << endl;
	}

	WriteArrayBinFile(64, encripted);

	_getch();
}

void decript() {
	unsigned short encripted[64];
	char V[8][8];
	char a, b;
	ReadArrayBinFile(64, encripted);
	unsigned short i, j;
	for (int k = 0; k < 64; k++) {
	  i = encripted[k] >> 13;
	  j = ((encripted[k] & 0b0000000000001110) >> 1);
	  a = (encripted[k] & 0b0001111000000000) >> 9;
	  b = encripted[k] & 0b0000000011110000;
	  V[i][j] = a | b;
	}
	cout << endl << "Decripted data: " << endl;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << V[i][j] << '|';
		}
		cout << endl;
	}
}

void task2() {

	char ch;
	do {
		cout << "\n  Select operation:   \n";
		cout << "    1.  Encript \n";
		cout << "    2.  Decript \n";
		cout << "    3.  Exit \n";

		ch = _getch();
		switch (ch) {
		case '1': encript(); break;
		case '2': decript(); break;
		}
	} while (ch != '3');
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
    cout << " file encryption \n";
	char S[100];
	cout << "Enter" << endl;
	cin.get(S, 100);
	int n = strlen(S);
	cout << S << endl; 
	for (int i = 0; i < n; i++) {
		S[i] = S[i] ^ (255 - i%256);
	}
	cout << S << endl;

	for (int i = 0; i < n; i++) {
		S[i] = S[i] ^ (255 - i % 256);
	}
	cout << S << endl;

	
	_getch();

}


