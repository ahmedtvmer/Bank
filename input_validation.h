#pragma once
#include <iostream>
#include <string>
using namespace std;

bool IsNumberBetween(int number, int from, int to)
{
	if (number > from && number < to)
	{
		return true;
	}
	return false;
}
bool IsNumberBetween(double number, double from, double to)
{
	if (number > from && number < to)
	{
		return true;
	}
	return false;
}
short ReadShortBetween(short min, short max, string message = "Invalid input, enter again\n")
{
	short value;
	while (true)
	{
		cin >> value;
		if (cin.fail() || value < min || value > max)
		{
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << message;
		}
		else
		{
			return value;
		}
	}
}

int  ValidateInt(string message = "Invalid input, enter again\n")
{
	int number;
	while (!(cin >> number)) {
		cout << message << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return number;
}
float  ValidateDouble(string message = "Invalid input, enter again\n")
{
	float number;
	while (!(cin >> number)) {
		cout << message << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return number;
}
string ReadString()
{
	string  S1;
	getline(cin, S1);
	return S1;
}

