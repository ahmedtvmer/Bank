#pragma once
#include "Currencies.h"
#include "ScreenHeader.h"

class clsFindCurrency : protected ScreenHeader
{
	static void _FindCurrency()
	{
		cout << "Find by Code [1] or Country [2]: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		short choice = ReadShortBetween(1, 2);
		clsCurrencies Currency = clsCurrencies::FindByCode("EGP");
		if (choice == 1)
		{
			cout << "Please enter Currency Code: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string Code = ReadString();
			Currency = clsCurrencies::FindByCode(Code);
		}
		else if (choice == 2)
		{
			cout << "Please enter Currency Country: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string Country = ReadString();
			Currency = clsCurrencies::FindByCountry(Country);
		}
		if (clsCurrencies::IsCurrencyExist(Currency.Code()))
			Currency.PrintCurrencyCard();
		else
			cout << "Currency not found!\n";
	}
public :
	static void FindCurrencyScreen()
	{
		DrawHeader("\t Find Currency");
		_FindCurrency();
	}
};