#pragma once
#include <iostream>
#include "ScreenHeader.h"
#include "Person.h"
#include "User.h"
#include "input_validation.h"

class clsDeleteUserScreen :protected ScreenHeader
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
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {

        DrawHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        UserName = ReadString();
        while (!User::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = ReadString();
        }

        User User1 = User::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

