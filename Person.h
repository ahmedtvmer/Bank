#pragma once
#include <iostream>
using namespace std;

class Person {
	string _firstName;
	string _lastName;
	string _email;
	string _phone;
public:
	Person(string fname, string lname, string email, string phone) :
		_firstName(fname), _lastName(lname), _email(email), _phone(phone)
	{}
	string getFirstName()
	{
		return _firstName;
	}
	void setFirstName(string fname)
	{
		_firstName = fname;
	}
	string getLastName()
	{
		return _lastName;
	}
	void setLastName(string lname)
	{
		_lastName = lname;
	}
	string getFullName()
	{
		return _firstName + " " + _lastName;
	}
	string getEmail()
	{
		return _email;
	}
	void setEmail(string email)
	{
		_email = email;
	}
	string getPhone()
	{
		return _phone;
	}
	void setPhone(string phone)
	{
		_phone = phone;
	}

};