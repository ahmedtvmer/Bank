#pragma once
#include <iostream>
#include "ScreenHeader.h"
#include "Person.h"
#include "User.h"
#include "input_validation.h"

class clsFindUserScreen :protected ScreenHeader
{

private:
    static void _PrintUser(User User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.getFullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        DrawHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = ReadString();
        while (!User::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = ReadString();
        }

        User User1 = User::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }

};

