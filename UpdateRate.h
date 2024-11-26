#pragma once
#include "Currencies.h"
#include "ScreenHeader.h"

class clsUpdateCurrencyRate : protected ScreenHeader
{
	static void _UpdateRate()
	{
		cout << "Please enter the currency code: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string Code = ReadString();
		while(!clsCurrencies::IsCurrencyExist(Code))
		{
			cout << "Invalid code, try again: ";
			Code = ReadString();
		}
		clsCurrencies Currency = clsCurrencies::FindByCode(Code);
		Currency.PrintCurrencyCard();
		cout << "Enter new rate: ";
		float newRate = ValidateDouble();
		Currency.UpdateRate(newRate);
		Currency.PrintCurrencyCard();
	}
public:
	static void UpdateRateScreen()
	{
		DrawHeader("Updating Rate");
		_UpdateRate();
	}
};
