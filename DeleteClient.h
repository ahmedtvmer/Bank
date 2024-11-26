#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"

class DeleteClient : protected ScreenHeader
{
	static void _DeleteClient()
	{
		cout << "Enter the account number of the client to delete: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string accNum = ReadString();
		while (!BankClient::IsClientExist(accNum))
		{
			cout << "\t\t\t\t\tThis account number is not existed, enter a valid one: ";
			accNum = ReadString();
		}
		BankClient client = BankClient::Find(accNum);
		client.Print();
		char flag = 'A';
		while (flag != 'N' && flag != 'Y')
		{
			cout << "\t\t\t\t\tAre you sure you want to delete this client? Y/N\n";
			cin >> flag;
			flag = toupper(flag);
			if (flag == 'Y')
				break;
			else if (flag == 'N')
				return;
		}
		BankClient::SaveResults results = client.save(BankClient::flag::fDelete);
		switch (results)
		{
		case BankClient::FailedEmpty:
			cout << "\n\t\t\t\t\tError account was not saved because it's empty";
			break;
		case BankClient::Succeeded:
			cout << "\n\t\t\t\t\tAccount Delete Successfully :-)\n";
			break;
		}
	}
public:
	static void DeleteClientScreen()
	{
		DrawHeader("\tDeleting Client");
		_DeleteClient();
	}
};
