// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>


using namespace std;
#define SPASE 32

const int y = 24;
const int x = 60;


void Ball(int** field) {
	field[12][30] = 8;
}
void frame(int** field) {
	for (int j = 1; j < y; j++) {//correct
		field[j][0] = 5;
	}
	for (int j = 1; j < y; j++) {
		field[j][x - 1] = 5;
	}
	for (int j = 1; j < x; j++) {
		field[0][j] = 6;
	}
	for (int j = 1; j < x; j++) {
		field[y - 1][j] = 6;
	}
}
void GeneratePlayers(int** field) {
	srand(time(NULL));
	//1 team
	field[rand() % 12 + 1][rand() % 30 + 1] = 9;
	// 2 team
	field[rand() % 12 + 11][rand() % 30 + 29] = 10;
}

void incilization(int** field,int check)
{
	for (int i = 0; i < x; i++)
		field[i] = new int[x + 1];
	
	for (int j = 1; j < y - 1; j++) {
		for (int i = 1; i < x - 1; i++) {
			field[j][i] = 0;
		}
	}
	field[0][0] = 7;
	field[y - 1][0] = 7;
	field[0][x - 1] = 7;
	field[y - 1][x - 1] = 7;
	Ball(field);
	frame(field);
	if (check > 0) {
		GeneratePlayers(field);
	}
	
}





void showArea(int** field) {

	char symbol[8] = { '.','--','|',' ','+','a','b' };
	for (int i = 0; i < y; i++) //цикл по строкам
	{
		for (int j = 0; j < x; j++) //цикл по столбцам
		{
			switch (field[i][j])
			{
			case 0: cout << symbol[3]; continue;
			case 5: cout << symbol[2]; continue;
			case 6: cout << symbol[1]; continue;
			case 7: cout << symbol[0]; continue;
			case 8: cout << symbol[4]; continue;
			case 9: cout << symbol[5]; continue;
			case 10: cout << symbol[6]; continue;
			}
		}
		cout << endl;
	}
}

//int Game(int** field,int check) {
//	
//			
//			
//
//}

int main()
{
	int check = 0;
	cout << "Press Space if u want to add mates " << endl;
	int** field = new int* [100];

	incilization(field, check);
	showArea(field);
	cout << endl;
	while (true) {
		if (_kbhit()) {
			int players = _getch();
			switch (players) {

			case SPASE:
				return main();
				break;
			}


	}
	}

}

	




