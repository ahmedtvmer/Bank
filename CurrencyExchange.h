#pragma once
#include "Currencies.h"
#include "ListCurrencies.h"
#include "FindCurrency.h"
#include "UpdateRate.h"
#include "CurrencyCalculator.h"

class clsCurrencyEchange : protected ScreenHeader
{
	enum eChoice {eList = 1, eFind, eUpdate, eCalculator};
	static void _PrintCurrencyExchangeMenu()
	{
		cout << "\t\t\t\t\t[1] List Currencies\n";
		cout << "\t\t\t\t\t[2] Find Currency\n";
		cout << "\t\t\t\t\t[3] Update Rate\n";
		cout << "\t\t\t\t\t[4] Currency Calculator\n";
		cout << "\t\t\t\t\t[5] Main Menu\n";
		cout << "\t\t\t\t\t______________________________________\n";
	}
	static eChoice _ReadMenuChoice()
	{
		cout << "\t\t\t\t\tChoose what do you want to do [1:5]: ";
		short choice = ReadShortBetween(1, 5);
		return (eChoice)choice;
	}
	static void _ListCurrenciesScreen()
	{
		clsListCurrencies::ListCurrenciesScreen();
	}
	static void _FindCurrencyScreen()
	{
		clsFindCurrency::FindCurrencyScreen();
	}
	static void _UpdateRateScreen()
	{
		clsUpdateCurrencyRate::UpdateRateScreen();
	}
	static void _CalculatorCurrencyScreen()
	{
		clsCurrencyCalculator::CurrencyCalculatorScreen();
	}
	static void _PerfromMenuChoice(eChoice choice)
	{
		switch (choice)
		{
		case clsCurrencyEchange::eList:
			system("cls");
			_ListCurrenciesScreen();
			_GoBackToCurrencyEchangeMenu();
			break;
		case clsCurrencyEchange::eFind:
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrencyEchangeMenu();
			break;
		case clsCurrencyEchange::eUpdate:
			system("cls");
			_UpdateRateScreen();
			_GoBackToCurrencyEchangeMenu();
			break;
		case clsCurrencyEchange::eCalculator:
			system("cls");
			_CalculatorCurrencyScreen();
			_GoBackToCurrencyEchangeMenu();
			break;
		}
	}
	static void _GoBackToCurrencyEchangeMenu()
	{
		cout << setw(37) << left << "" <<
			"\n\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyExchange();
	}
public :
	static void ShowCurrencyExchange()
	{
		system("cls");
		DrawHeader("\t Currency Exchange");
		_PrintCurrencyExchangeMenu();
		_PerfromMenuChoice(_ReadMenuChoice());
	}
};
