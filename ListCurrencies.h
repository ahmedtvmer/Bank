#pragma once
#include "ScreenHeader.h"
#include "Currencies.h"

class clsListCurrencies : protected ScreenHeader
{
	static void _PrintCurrency(clsCurrencies Currency)
	{
		cout << "\t\t| " << setw(30) << Currency.Country();
		cout << "| " << setw(10) << Currency.Code();
		cout << "| " << setw(40) << Currency.CurrencyName();
		cout << "| " << Currency.Rate() << endl;
	}
	static void _ShowCurrencies()
	{
		vector<clsCurrencies> vCurrencies = clsCurrencies::GetCurrenciesList();
		cout << "\t\t| " << setw(30) << "Country";
		cout << "| " << setw(10) << "Code";
		cout << "| " << setw(40) << "Currency Name";
		cout << "| " << "Currency Rate" << endl;
		cout << "\n\t\t___________________________________________________________________";
		cout <<	"________________________\n\n";
		for (clsCurrencies C : vCurrencies)
		{
			_PrintCurrency(C);
		}
		cout << "\n\t\t___________________________________________________________________";
		cout << "________________________\n\n";
	}
public:
	static void ListCurrenciesScreen()
	{
		_ShowCurrencies();
	}
};
