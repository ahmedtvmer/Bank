#pragma once
#include "BankClient.h"
#include "ScreenHeader.h"

class Withdraw : protected ScreenHeader
{
	static void _Withdraw()
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
		cout << "Please enter withdraw amount: ";
		float withdrawAmount = ValidateDouble();
		while (withdrawAmount > client.GetBalance())
		{
			cout << "You are withdrawing more than the amount in your balance, try again: ";
			withdrawAmount = ValidateDouble();
		}
		client.SetBalance(client.GetBalance() - withdrawAmount);
		BankClient::SaveResults result = client.save(BankClient::fUpdate);
		switch (result)
		{
		case BankClient::FailedEmpty:
			break;
		case BankClient::Succeeded:
			cout << "Your new balance after withdrawing is: " << client.GetBalance() << endl;
			break;
		}
	}
public:
	static void WithdrawScreen()
	{
		DrawHeader("Withdraw Screen");
		_Withdraw();
	}
};
