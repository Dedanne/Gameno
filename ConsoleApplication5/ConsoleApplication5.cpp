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
	frame(field, n);
	for (int j = 1; j < n-1; j++) {
		for (int i = 1; i < n-1; i++) {
			field[j][i] = 0;
		}
	}
	field[0][0] = 0;
	field[n - 1][0] = 0;
	//field[0][n-1]=
}



int main()
{
	int n = 20;
	int** field = new int*[100];
	incilization(field, n);
	show(field,n);
}


