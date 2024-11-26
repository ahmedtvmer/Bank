#pragma once
#include "ScreenHeader.h"
#include "BankClient.h"
#include "Deposite.h"
#include "Withdraw.h"
#include "TotalBalances.h"
#include "Transfer.h"

class Transactions : protected ScreenHeader
{
	enum _TransactionsScreenOptions {Deposite = 1, Withdraw, Transfer , TotalBalances};
	static void _DepositeScreen()
	{
		Deposite::DepositeScreen();
	}
	static void _WithdrawScreen()
	{
		Withdraw::WithdrawScreen();
	}
	static void _TransferScreen()
	{
		Transfer::TransferScreen();
	}
	static void _TotalBalancesScreen()
	{
		TotalBalances::TotalBalancesScreen();
	}
	static short _ReadMenuOptions()
	{
		cout << "\t\t\t\t\tChoose what do you want to do [1:5]?\n";
		short choice = ReadShortBetween(1, 5);
		return choice;
	}
	static void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" <<
			"\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		system("cls");
		_ShowTransactionsMenu();
	}
	static void _PerformMenuOptions(_TransactionsScreenOptions Option)
	{
		switch (Option)
		{
		case Transactions::Deposite:
			system("cls");
			_DepositeScreen();
			_GoBackToTransactionsMenu();
			break;
		case Transactions::Withdraw:
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case Transactions::Transfer:
			system("cls");
			_TransferScreen();
			_GoBackToTransactionsMenu();
			break;
		case Transactions::TotalBalances:
			system("cls");
			_TotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
	}
	static void _ShowTransactionsMenu()
	{
		DrawHeader("\tTransactions");
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Transfer.\n";
		cout << setw(37) << left << "" << "\t[4] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMenuOptions((_TransactionsScreenOptions)_ReadMenuOptions());
	}
public:
	static void TransactionsScreen()
	{
		_ShowTransactionsMenu();
	}
};

