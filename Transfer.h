#pragma once
#include "BankClient.h"
#include "ScreenHeader.h"

class Transfer : protected ScreenHeader
{
	static void _TransferRegisters(BankClient clientFrom, BankClient clientTo,
		float TransferAmount , string delim = "#//#")
	{
		ofstream TransferRegisters("TransferRegisters.txt", ios::app);
		string line = User::getCurrentDateTime() + delim
			+ clientFrom.GetAccountNumber() + delim
			+ clientTo.GetAccountNumber() + delim
			+ to_string(TransferAmount) + delim
			+ to_string(clientFrom.GetBalance()) + delim
			+ to_string(clientTo.GetBalance()) + delim
			+ CurrentUser.GetUserName();
		TransferRegisters << line << endl;
		TransferRegisters.close();
	}
	static void _PrintClient(BankClient client)
	{
		cout << "Client Card\n";
		cout << "______________________________\n\n";
		cout << "Full Name   : " << client.getFullName() << endl;
		cout << "Acc. Number : " << client.GetAccountNumber() << endl;
		cout << "Balance     : " << client.GetBalance() << endl;
		cout << "\n______________________________\n\n";
	}
	static void _Transfer()
	{
		cout << "Please enter the account number you want to transfer from: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string accNum1 = ReadString();
		while (!BankClient::IsClientExist(accNum1))
		{
			cout << "Invalid account number, please try again: ";
			accNum1 = ReadString();
		}
		BankClient clientFrom = BankClient::Find(accNum1);
		_PrintClient(clientFrom);

		cout << "Please enter the account number you want to transfer to: ";
		string accNum2 = ReadString();
		while (!BankClient::IsClientExist(accNum2))
		{
			cout << "Invalid account number, please try again: ";
			accNum2 = ReadString();
		}
		BankClient clientTo = BankClient::Find(accNum2);
		_PrintClient(clientTo);

		cout << "Enter transfer amount: ";
		float transferAmount = ValidateDouble();
		while (transferAmount > clientFrom.GetBalance())
		{
			cout << "Transfer amount exceed the availible balance, please try again: ";
			transferAmount = ValidateDouble();
		}
		clientFrom.SetBalance(clientFrom.GetBalance() - transferAmount);
		clientFrom.save();
		clientTo.SetBalance(transferAmount + clientTo.GetBalance());
		clientTo.save();
		_TransferRegisters(clientFrom, clientTo, transferAmount);
		cout << "Proccess done successfully!\n";
		_PrintClient(clientFrom);
		_PrintClient(clientTo);
	}
public:
	static void TransferScreen()
	{
		DrawHeader("\t Transfering");
		_Transfer();
	}
};
