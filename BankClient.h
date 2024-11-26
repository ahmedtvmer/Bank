#pragma once
#include <fstream>
#include "Person.h"
#include "clsString.h"
#include "input_validation.h"
#include "utilities.h"

class BankClient : public Person
{
	enum Mode { Empty, Update } _mode;
	string _accountNumber;
	string _pinCode;
	float _balance;

	static BankClient _ConvertLineToObject(string line, string delim = "#//#")
	{
		vector<string> clientRecord = split(line, delim);
		return BankClient(Mode::Update, clientRecord[0], clientRecord[1],
			clientRecord[2], clientRecord[3], clientRecord[4], (clientRecord[5]), stof(clientRecord[6]));
	}
	static string _ConvertObjectToLine(BankClient client, string delim = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += client.getFirstName() + delim;
		ClientRecord += client.getLastName() + delim;
		ClientRecord += client.getEmail() + delim;
		ClientRecord += client.getPhone() + delim;
		ClientRecord += client.GetAccountNumber() + delim;
		string tempPinCode = client.GetPinCode();
		ClientRecord += (tempPinCode) + delim;
		ClientRecord += to_string(client.GetBalance());

		return ClientRecord;
	}
	static BankClient _GetEmptyClientObject()
	{
		return BankClient(Mode::Empty, "", "", "", "", "", "", 0);
	}
	static  vector <BankClient> _LoadClientsDataFromFile()
	{

		vector <BankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				BankClient Client = _ConvertLineToObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}
	static void _SaveCleintsDataToFile(vector <BankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (BankClient C : vClients)
			{
				DataLine = _ConvertObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}
	void _Update()
	{
		vector <BankClient> Clients = _LoadClientsDataFromFile();
		for (BankClient& client : Clients)
		{
			if (client.GetAccountNumber() == _accountNumber)
			{
				client = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(Clients);
	}
	void _Add()
	{
		vector<BankClient> clients = _LoadClientsDataFromFile();
		this->_mode = Mode::Update;
		clients.push_back(*this);
		_SaveCleintsDataToFile(clients);
	}
	void _Delete()
	{
		vector<BankClient> clients = _LoadClientsDataFromFile();
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i].GetAccountNumber() == this->GetAccountNumber())
				clients.erase(clients.begin() + i--);
		}
		_SaveCleintsDataToFile(clients);
	}
public:
	BankClient(Mode mode, string fname, string lname, string email, string phone, string accountNumber,
		string pinCode, float balance) : Person(fname, lname, email, phone)
	{
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_balance = balance;
	}
	string GetAccountNumber()
	{
		return _accountNumber;
	}
	void SetAccountNumber(string accountNumber)
	{
		_accountNumber = accountNumber;
	}
	string GetPinCode()
	{
		return _pinCode;
	}
	void SetPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}
	float GetBalance()
	{
		return _balance;
	}
	void SetBalance(float balance)
	{
		_balance = balance;
	}
	static bool IsEmpty(BankClient client)
	{
		return (client._mode == Mode::Empty);
	}
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n______________________";
		cout << "\nFirst Name    :\t" << getFirstName();
		cout << "\nLast Name     :\t" << getLastName();
		cout << "\nEmail         :\t" << getEmail();
		cout << "\nPhone         :\t" << getPhone();
		cout << "\nAccount Number:\t" << GetAccountNumber();
		cout << "\nPassword      :\t" << GetPinCode();
		cout << "\nBalance       :\t" << GetBalance();
		cout << "\n______________________\n";
	}
	static BankClient Find(string AccountNumber)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				BankClient Client = _ConvertLineToObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static BankClient Find(string AccountNumber, string pinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				BankClient Client = _ConvertLineToObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == pinCode)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string accountNumber)
	{
		BankClient Client = Find(accountNumber);
		return (!IsEmpty(Client));
	}
	enum SaveResults{FailedEmpty, Succeeded};
	enum flag {fDelete, fUpdate};
	SaveResults save(flag f = flag::fUpdate)
	{
		switch (_mode)
		{
		case BankClient::Empty:
			if (this->GetAccountNumber() != "")
			{
				_Add();
				return SaveResults::Succeeded;
			}
			return SaveResults::FailedEmpty;
		case BankClient::Update:
			if (f == flag::fDelete)
				_Delete();
			else 
				_Update();
			return SaveResults::Succeeded;
		}
	}
	static vector<BankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
};
