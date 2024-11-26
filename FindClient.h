#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"

class FindClient : protected ScreenHeader
{
	static void _FindClient()
	{
		cout << "Enter the account number to find: \n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string accNum = ReadString();
		while (!BankClient::IsClientExist(accNum))
		{
			cout << "This client is not found, please enter another one: ";
			accNum = ReadString();
		}
		BankClient client = BankClient::Find(accNum);
		client.Print();
	}
public:
	static void FindClientScreen()
	{
		DrawHeader("\tFinding Client");
		_FindClient();
	}
};
