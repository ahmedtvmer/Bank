#include <iostream>
#include <iomanip>
#include "User.h"
#include "Global.h"
#include <ctime>
#pragma once
using namespace std;

class ScreenHeader
{
    static std::string _getCurrentDate() {
        std::time_t t = std::time(nullptr);
        std::tm localTime;
        localtime_s(&localTime, &t);

        char buffer[11]; 
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);
        return std::string(buffer);
    }
public:
    static void DrawHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
        cout << "\t\t\t\t\tDate: " << _getCurrentDate() << endl << endl;
    }

};

