#pragma once
#include "BankClient.h"
#include "ScreenHeader.h"
#include "MainScreen.h"

class Deposite : protected ScreenHeader
{
	static void _Deposite()
	{
		cout << "Enter account number: \n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string accNum = ReadString();
		while (!BankClient::IsClientExist(accNum))
		{
			cout << "User not found, please enter a valid account number!\n";
			accNum = ReadString();
		}
		BankClient client = BankClient::Find(accNum);
		client.Print();
		cout << "Please enter deposite amount: ";
		float depositeAmount = ValidateDouble();
		client.SetBalance(client.GetBalance() + depositeAmount);
		BankClient::SaveResults result = client.save(BankClient::fUpdate);
		switch (result)
		{
		case BankClient::FailedEmpty:
			break;
		case BankClient::Succeeded:
		cout << "Your new balance after depositing is: " << client.GetBalance() << endl;
			break;
		}
	}
public:
	static void DepositeScreen()
	{
		DrawHeader("Deposite Screen");
		_Deposite();
	}
};