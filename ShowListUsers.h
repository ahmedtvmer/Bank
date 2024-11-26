#include "User.h"
#include <iostream>
#include "ScreenHeader.h"
#include <iomanip>

class ShowListUsers : protected ScreenHeader
{
	static void _PrintUserRecordLine(User User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName(); //User.UserName;
        cout << "| " << setw(25) << left << User.getFullName();/*User.FullName();*/
        cout << "| " << setw(12) << left << User.getPhone(); //User.Phone;
        cout << "| " << setw(20) << left << User.getEmail();//User.Email;
        cout << "| " << setw(10) << left << User.GetPassword();/*User.Password;*/
        cout << "| " << setw(12) << left << User.GetPermissions();/*User.Permissions;*/

    }
public:

    static void ShowUsersList()
    {
        vector <User> vUsers = User::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        DrawHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (User User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};