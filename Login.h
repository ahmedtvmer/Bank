#pragma once
#include "User.h"
#include "ScreenHeader.h"
#include "MainScreen.h"
#include "input_validation.h"
#include "Global.h"

class Login : protected ScreenHeader
{
	static void _RegisterLogins(string delim = "#//#")
	{
		ofstream RegisterLogins("LoginRegisters.txt", ios::app);
		string line = User::getCurrentDateTime() + delim
			+ CurrentUser.GetUserName() + delim + EncryptText(CurrentUser.GetPassword());
			RegisterLogins << line << endl;
			RegisterLogins.close();
	}
	static bool _IsValidLogin(string username, string password)
	{
		User user = User::Find(username, password);
		if (user.IsEmpty())
			return false;
		CurrentUser = user;
		_RegisterLogins();
		return true;
	}
	static void _Login()
	{
		cout << "Enter your username: ";
		string username = ReadString();
		cout << "Enter your password: ";
		string password = ReadString();
		short counter = 0;
		while (!_IsValidLogin(username, password))
		{
			if (counter++ == 2)
			{
				cout << "\nYou exceeded the limit, please try again later!\n";
				exit(0);
			}
			cout << "Wrong username/password, please try again\n";
			cout << "Enter your username: ";
			username = ReadString();
			cout << "Enter your password: ";
			password = ReadString();
		}
		MainScreen::ShowMenu();
	}
public:
	static void LoginScreen()
	{
		system("cls");
		DrawHeader("\t\t Login");
		_Login();
	}
};