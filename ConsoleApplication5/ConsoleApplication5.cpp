#include "pch.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>


using namespace std;
#define GeneratePlayer 110
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

const int y = 24;
const int x = 60;
int xb = x / 2;
int yb = y / 2;


void SavePositionPlayers(int** field, int* x1, int* x2, int* y1, int* y2);

void Ball(int** field) {
	field[yb][xb] = 8;
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

void GeneratePlayers(int** field, int* x1, int* x2, int* y1, int* y2) {
	srand(time(NULL));
	
	for (int i = 0; i < 3; i++) {
		y1[i] = rand() % 12 + 1;
		x1[i] = rand() % 30 + 1;
		
		
		
		y2[i] = rand() % 12 + 11;
		x2[i] = rand() % 30 + 29;
		
		}
	SavePositionPlayers(field, y1, y2, x1, x2);
}

void SavePositionPlayers(int** field, int* x1, int* x2, int* y1, int* y2) {
	for (int i = 0; i < 3; i++) {
		field[y1[i]][x1[i]] = 9;
		field[y2[i]][x2[i]] = 10;
	}
}

void incilization(int** field,int* x1, int* x2, int* y1, int* y2)
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
    //SavePositionPlayers(field,y1,y2,x1,x2);
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

void Game(int** field, int* x1, int* x2, int* y1, int* y2) {
	incilization(field,x1,x2,y1,y2);
	showArea(field);
	cout << endl;
	while (true) {
		if (_kbhit()) {
			int players = _getch();
			switch (players) {

			case GeneratePlayer:
				
				GeneratePlayers(field, x1, x2, y1, y2);
				return Game(field,x1,x2,y1,y2);
				break;
			case SPACE:
			    return Game(field, x1, x2, y1, y2);
				break;
			case UP:
				yb--;
				if (yb == 1)
					yb = y - 1;
				return Game(field, x1, x2, y1, y2);
				break;
			case DOWN:
				yb++;
				if (yb == y - 1)
					yb = 1;
				return Game(field, x1, x2, y1, y2);
				break;
			case LEFT:
				xb--;
				if (xb == 1)
					xb = x - 1;
				return Game(field, x1, x2, y1, y2);
				break;
			case RIGHT:
				xb++;
				if (xb == x - 1);
				xb == 1;
				return Game(field, x1, x2, y1, y2);
				break;
			}
		}
	}
}

int main()
{
	int* y1 = new int[10];
	int* x1 = new int[10];
	int* x2 = new int[10];
	int* y2 = new int[10];
	
	cout << "Press 'N' if u want to add mates " << endl;
	int** field = new int* [100];
	Game(field,x1,x2,y1,y2);
}

	




