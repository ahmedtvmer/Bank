#pragma once
#include "Currencies.h"
#include "ScreenHeader.h"

class clsCurrencyCalculator : protected ScreenHeader
{
	static float _ExchangingCurrencies(clsCurrencies currency1, clsCurrencies currency2, float ExchangingAmount)
	{
		float CalculatedResult;
		if (currency2.Code() == "USD")
			CalculatedResult = ExchangingAmount / currency1.Rate();
		else if(currency1.Code() == "USD")
			CalculatedResult = ExchangingAmount * currency2.Rate();
		else
		{
			float newRate = (ExchangingAmount / currency1.Rate()) / (ExchangingAmount / currency2.Rate());
			CalculatedResult = ExchangingAmount * newRate;
		}
		return CalculatedResult;
	}
	static void _Calculator()
	{
		char flag;
		do
		{
			cout << "Please enter the currency code you would change from: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string Code1 = ReadString();
			while (!clsCurrencies::IsCurrencyExist(Code1))
			{
				cout << "Invalid code, please try again: ";
				Code1 = ReadString();
			}
			clsCurrencies Currency1 = clsCurrencies::FindByCode(Code1);
			Currency1.PrintCurrencyCard();

			cout << "Please enter the currency code you would change into: ";
			string Code2 = ReadString();
			while (!clsCurrencies::IsCurrencyExist(Code2))
			{
				cout << "Invalid code, please try again: ";
				Code2 = ReadString();
			}
			clsCurrencies Currency2 = clsCurrencies::FindByCode(Code2);
			cout << "Please enter the amount to exchange: ";
			float ExchangingAmount = ValidateDouble();
			float Result = _ExchangingCurrencies(Currency1, Currency2, ExchangingAmount);
			cout << "\n" << ExchangingAmount << " " << Currency1.Code() <<
				" = " << Result << " " << Currency2.Code() << endl << endl;
			cout << "Do you wish to continue? [Y/N]: ";
			cin >> flag;
			if (toupper(flag) == 'N')
				break;
			else if (toupper(flag) == 'Y')
			{
				system("cls");
				DrawHeader("\t Currency Calculator");
				continue;
			}
			while(toupper(flag) != 'N' && toupper(flag) != 'Y')
			{
				cout << "Invalid, try again: ";
				cin >> flag;
			}
		} while (true);
	}
public:
	static void CurrencyCalculatorScreen()
	{
		DrawHeader("\t Currency Calculator");
		_Calculator();
	}
};
