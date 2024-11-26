#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"
#include "MainScreen.h"

class TotalBalances : protected ScreenHeader
{
	static void _PrintClient(BankClient client)
	{
		cout << "\t\t\t\t| " << setw(20) << client.GetAccountNumber()
			<< "| " << setw(30) << client.getFullName()
			<< "| " << setw(15) << client.GetBalance() << endl;
	}
	static void _PrintAll()
	{
		cout << "\t\t\t________________________________________________________________________\n\n";
		cout << "\t\t\t\t| " << setw(20) << "Account Number"
			<< "| " << setw(30) << "Client Name"
			<< "| " << setw(15) << "Balance" << endl;
		cout << "\t\t\t________________________________________________________________________\n\n";
		vector <BankClient> Clients = BankClient::GetClientsList();
		float totalBalances = 0;
		for (BankClient C : Clients)
		{
			_PrintClient(C);
			totalBalances += C.GetBalance();
		}
		cout << "\n\n\t\t\t_________________________________________________________________________\n\n";
		cout << "\t\t\t\t\t\tTotal Balances is : " << totalBalances << endl;
	}
public:
	static void TotalBalancesScreen()
	{
		DrawHeader("\tTotal Balances Screen");
		_PrintAll();
	}
};