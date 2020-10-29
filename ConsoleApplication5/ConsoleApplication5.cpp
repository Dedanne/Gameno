// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void frame(int **field, int n) {
	for (int j = 1; j < n; j++) {//correct
		field[j][0] = 5;
	}
	for (int j = 1; j < n; j++) {
		field[j][n - 1] = 5;
	}
	for (int j = 1; j < n; j++) {
		field[0][j] = 6;
	}
	for (int j = 1; j < n; j++) {
		field[n-1][j] = 6;
	}
}

void incilization(int**field,int n)
{
	for (int i = 0; i < n; i++)
		field[i] = new int[n+1];
	frame(field, n);
	for (int j = 1; j <n-1; j++) {
		for (int i = 1; i < n-1; i++) {
			field[j][i] = 0;
		}
	}
	field[0][0] = 7;
	field[n - 1][0] = 7;
	field[0][n - 1] = 7;
	field[n - 1][n - 1] = 7;
}


void show(int**field, int n) {
	
	char symbol[6] = { ' ','--','|','*' };
	for (int i = 0; i < n; i++) //цикл по строкам
	{
		for (int j = 0; j < n; j++) //цикл по столбцам
		{
			switch (field[i][j])
			{
			case 0: cout << symbol[3]; continue;
			case 5: cout << symbol[2]; continue;
			case 6: cout << symbol[1]; continue;
			case 7: cout << symbol[0]; continue;

			}
		}
	}
}



int main()
{
	int n = 20;
	int** field = new int*[100];
	incilization(field, n);
	show(field,n);
}


