#pragma once

#include "ScreenHeader.h"
#include <fstream>
#include <vector>
#include "input_validation.h"
#include <string>
#include "clsString.h"

class clsCurrencies : protected ScreenHeader
{
	enum eMode {Empty, Update} _Mode;
	string _Country, _Code, _CurrencyName;
	float _Rate;
	
	static clsCurrencies _ConvertFromLineToObject(string line, string delim = "#//#")
	{
		vector<string> object = split(line, delim);
		return clsCurrencies(eMode::Update, object[0], object[1], object[2], stof(object[3]));
	}
	static string _ConvertFromObjectToLine(clsCurrencies currency, string delim = "#//#")
	{
		string line = currency._Country + delim
			+ currency._Code + delim
			+ currency._CurrencyName + delim
			+ to_string(currency._Rate);
		return line;
	}
	static vector <clsCurrencies> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrencies> vCurrencies;
		fstream Currencies("Currencies.txt", ios::in);
		string line = "";
		while (getline(Currencies, line))
		{
			vCurrencies.push_back(_ConvertFromLineToObject(line));
		}
		Currencies.close();
		return vCurrencies;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrencies> Currency)
	{
		fstream Currencies("Currencies.txt", ios::out);
		for (clsCurrencies C : Currency)
		{
			Currencies << _ConvertFromObjectToLine(C) << endl;
		}
		Currencies.close();
	}
	void _Update()
	{
		vector<clsCurrencies> vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrencies& C : vCurrencies)
		{
			if (C._Code == _Code)
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}
	static clsCurrencies _GetEmptyCurrencyObject()
	{
		return clsCurrencies(eMode::Empty, "", "", "", 0);
	}
public:
	clsCurrencies(eMode Mode, string Country, string Code, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	string Country()
	{
		return _Country;
	}
	string Code()
	{
		return _Code;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	float Rate()
	{
		return _Rate;
	}
	void UpdateRate(float newRate)
	{
		_Rate = newRate;
		_Update();
	}
	bool isEmpty()
	{
		return (_Mode == eMode::Empty);
	}
	static clsCurrencies FindByCode(string Code)
	{
		vector<clsCurrencies> vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrencies C : vCurrencies)
		{
			if (UpperAllString(C.Code()) == UpperAllString(Code))
				return C;
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrencies FindByCountry(string Country)
	{
		vector<clsCurrencies> vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrencies C : vCurrencies)
		{
			if (UpperAllString(C.Country()) == UpperAllString(Country))
				return C;
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string Code)
	{
		clsCurrencies c = FindByCode(Code);
		return(!c.isEmpty());
	}
	static vector<clsCurrencies> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	void PrintCurrencyCard()
	{
		cout << "\nCurrency Card";
		cout << "\n____________________________________\n\n";
		cout << "Country  : " << _Country << endl;
		cout << "Code     : " << _Code << endl;
		cout << "Name     : " << _CurrencyName << endl;
		cout << "Rate(1$) : " << _Rate;
		cout << "\n____________________________________\n\n";
	}
};
