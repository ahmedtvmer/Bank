#pragma once
#include "ScreenHeader.h"
#include "input_validation.h"
#include "ShowClients.h"
#include "AddClient.h"
#include "DeleteClient.h"
#include "UpdateClient.h"
#include "FindClient.h"
#include "Transactions.h"
#include "ManageUsers.h"
#include <cstdlib>
#include "Global.h"
#include "CurrencyExchange.h"

class MainScreen : protected ScreenHeader
{
	enum _MainScreenOptions{ShowClients = 1, AddClient, DeleteClient, UpdateClient, FindClient,
						Transactions, ManageUsers, CurrencyExchange, Logout};
	static void _ShowClientsScreen()
	{
		ShowClients::ShowClientsScreen();
	}
	static void _AddClientScreen()
	{
		AddClient::AddClientScreen();
	}
	static void _DeleteClientScreen()
	{
		DeleteClient::DeleteClientScreen();
	}
	static void _UpdateClientScreen()
	{
		UpdateClient::UpdateClientScreen();
	}
	static void _FindClientScreen()
	{
		FindClient::FindClientScreen();
	}
	static void _TransactionsScreen()
	{
		Transactions::TransactionsScreen();
	}
	static void _ManageUsersScreen()
	{
		ManageUsers::ShowManageUsersMenue();
	}
	static void _CurrencyExchangeScreen()
	{
		clsCurrencyEchange::ShowCurrencyExchange();
	}
	static void _LogoutScreen()
	{
		CurrentUser = User::Find("", "");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	static short _ReadMenuOptions()
	{
		cout <<  "\t\t\t\t\tChoose what do you want to do [1:9]?\n";
		short choice = ReadShortBetween(1, 9);
		return choice;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" <<
			"\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMenu();
	}
	static void _PerformMenuOptions(_MainScreenOptions Option)
	{
		switch (Option)
		{
		case MainScreen::ShowClients:
			system("cls");
			_ShowClientsScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::AddClient:
			system("cls");
			_AddClientScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::DeleteClient:
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::UpdateClient:
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::FindClient:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::Transactions:
			system("cls");
			_TransactionsScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::ManageUsers:
			system("cls");
			_ManageUsersScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::CurrencyExchange:
			system("cls");
			_CurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		case MainScreen::Logout:
			system("cls");
			_LogoutScreen();
			break;
		}
	}
public:
	static void ShowMenu()
	{
		system("cls");
		DrawHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMenuOptions((_MainScreenOptions)_ReadMenuOptions());
	}
};