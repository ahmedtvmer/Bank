#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;


int countLetters(string _value)
{
	int counter = 0;
	while (_value[counter])
	{
		counter++;
	}
	return counter;
}
int countUpperLetters(string _value)
{
	int Uppercounter = 0, counter = 0;
	while (_value[counter])
	{
		if(_value[counter] >= 'A' && _value[counter] <= 'Z')
			Uppercounter++;
		counter++;
	}
	return Uppercounter;
}
int countLowerLetters(string _value)
{
	int Lowercounter = 0, counter = 0;
	while (_value[counter])
	{
		if (_value[counter] >= 'a' && _value[counter] <= 'z')
			Lowercounter++;
		counter++;
	}
	return Lowercounter;
}
int countWords(string _value)
{
	int counter = 0, wordCounter = 1;
	while (_value[counter])
	{
		if (_value[counter] == ' ')
			wordCounter++;
		counter++;
	}
	return wordCounter;
}
void invertLettersCase(string _value)
{
	int counter = 0;
	while (_value[counter])
	{
		if(_value[counter] >= 'A' && _value[counter] <= 'Z')
		_value[counter++] += 32;
		else 
		_value[counter++] -= 32;
	}
}
string UpperAllString(string _value)
{
	for (char& ch : _value)
	{
		ch = toupper(ch);
	}
	return _value;
}
vector<string> split(string line, string delim)
{
	vector<string> separatedLine;
	int pos = 0;
	string substr;
	while ((pos = (int)line.find(delim)) != string::npos)
	{
		substr = line.substr(0, pos);
		separatedLine.push_back(substr);
		line.erase(0, pos + delim.length());
	}
	if(!line.empty())
		separatedLine.push_back(line);
	return separatedLine;
}

