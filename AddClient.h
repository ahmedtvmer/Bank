#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"

class AddClient : protected ScreenHeader
{
	 static void _ReadClientInfo(BankClient& client)
	{
		cout << "Enter client first name: \n";
		client.setFirstName(ReadString());

		cout << "Enter client last name: \n";
		client.setLastName(ReadString());

		cout << "Enter client email: \n";
		client.setEmail(ReadString());

		cout << "Enter client phone: \n";
		client.setPhone(ReadString());

		cout << "Enter client password: \n";
		client.SetPinCode(ReadString());

		cout << "Enter client balance: \n";
		client.SetBalance(ValidateDouble());
	}
	 static void _AddClient()
	{
		cout << "\t\t\t\t\tAdd a new account number to add new client: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string newAccNum = ReadString();
		while (BankClient::IsClientExist(newAccNum))
		{
			cout << "\t\t\t\t\tThis account number is already exist, enter a new account number: ";
			newAccNum = ReadString();
		}
		BankClient client = BankClient::Find(newAccNum);
		if (BankClient::IsEmpty(client))
		{
			client.SetAccountNumber(newAccNum);
			_ReadClientInfo(client);
			BankClient::SaveResults Result = client.save();
			switch (Result)
			{
			case BankClient::FailedEmpty:
				cout << "\nError account was not saved because it's empty";
				break;
			case BankClient::Succeeded:
				cout << "\nAccount Updated Successfully :-)\n";
				client.Print();
				break;
			}
		}
	}
public:
	static void AddClientScreen()
	{
		DrawHeader("Adding Client");
		_AddClient();
	}
};
