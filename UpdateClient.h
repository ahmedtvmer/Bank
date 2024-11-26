#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"

class UpdateClient : protected ScreenHeader
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
	static void _UpdateClient()
	{
		string accNum = "";
		cout << "Please enter client number: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		accNum = ReadString();
		while (!BankClient::IsClientExist(accNum))
		{
			cout << "User not found, please enter a valid account number!\n";
			accNum = ReadString();
		}
		BankClient client = BankClient::Find(accNum);
		client.Print();
		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
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
public:
	static void UpdateClientScreen()
	{
		DrawHeader("\tUpdating Client");
		_UpdateClient();
	}
};
