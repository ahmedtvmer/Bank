#pragma once
#include <iostream>
#include <random>
#include <string>
using namespace std;


enum Variation{CapitalLetter = 1, SmallLetter, MixedCharacters};
int RandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
char RandomCharacter(Variation v)
{
    switch (v)
    {
    case Variation::CapitalLetter:
        return char(RandomNumber('A', 'Z'));
    case Variation::SmallLetter:
        return char(RandomNumber('a', 'z'));
    case Variation::MixedCharacters:
        if (!RandomNumber(0, 1))
            return char(RandomNumber('A', 'Z'));
        else
            return char(RandomNumber('a', 'z'));
    default:
        break;
    }
}
string GenerateWord(Variation v, int numberOfLetters)
{
    string word = "";
    for (int i = 0; i < numberOfLetters; i++)
    {
		word += RandomCharacter(v);
    }
    return word;
}
string GenerateKey(Variation v)
{
    string key = "";
    for(int i = 0; i < 4; i++)
    {
        key += GenerateWord(v, 4);
        if(i != 3) 
            key += "-";
    }
    return key;
}
string GenerateKeys(Variation v, int numberOfKeys)
{
    string Keys = "";
    for (int i = 0; i < numberOfKeys; i++)
    {
        Keys += "Key [" + to_string(i + 1) + "] : " + GenerateKey(v) + "\n";
    }
    return Keys;
}
void Swap(int &n1, int &n2)
{
    n1 = n2 + n1;
    n2 = n1 - n2;
    n1 = n1 - n2;
}
void Swap(double &n1, double& n2)
{
    n1 = n2 + n1;
    n2 = n1 - n2;
    n1 = n1 - n2;
}
void Swap(string &s1, string &s2)
{
    string temp = s1;
    s1 = s2;
    s2 = temp;
}
void ShuffleArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(arr[i], arr[RandomNumber(0, size - 1)]);
    }
}
string EncryptText(string text, short EncryptionKey = 2)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] + EncryptionKey);
    }
    return text;
}
string DecryptText(string text, short EncryptionKey = 2)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] - EncryptionKey);
    }
    return text;
}


