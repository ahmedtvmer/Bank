#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"

class ShowClients : protected ScreenHeader
{
	static void _PrintClientRecordLine(BankClient Client)
	{

		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.getFullName();
		cout << "| " << setw(12) << left << Client.getPhone();
		cout << "| " << setw(20) << left << Client.getEmail();
		cout << "| " << setw(10) << left << Client.GetPinCode();
		cout << "| " << setw(12) << left << Client.GetBalance();

	}

	static void _ShowClientsList()
	{

		vector <BankClient> vClients = BankClient::GetClientsList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		DrawHeader(Title, SubTitle);

		

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (BankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
public:
	static void ShowClientsScreen()
	{
		_ShowClientsList();
	}
};