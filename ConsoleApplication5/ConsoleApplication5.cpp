// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void show(int**pole,int n)
{
	for (int j = 1; j < n-1; j++) {
		cout << pole[j][0] << "I";
	}
}

int main()
{
	int n = 20;
	int** field = new int*[100];
	show(field,n);
}


