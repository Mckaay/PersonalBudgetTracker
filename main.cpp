#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "PersonalMoneyTracker.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    PersonalMoneyTracker personalMoneyTracker("Users.xml","incomes.xml","expenses.xml");

    while(!personalMoneyTracker.getLoggedInUserId())
    {
        char decision;
        decision = personalMoneyTracker.displayLoginMenu();
        switch(decision)
        {
        case '1':
            personalMoneyTracker.registration();
            Methods::pauseProgram();
            break;
        case '2':
            personalMoneyTracker.loggingIn();
            Methods::pauseProgram();
            break;
        case '9':
            exit(0);
        default:
            cout << "Cos poszlo nie tak!" << endl;
            exit(0);
        }
        while(personalMoneyTracker.getLoggedInUserId())
        {
            system("cls");
            personalMoneyTracker.displayMainMenu();
            cin >> decision;

            switch(decision)
            {
            case '1':
                system("cls");
                personalMoneyTracker.addIncome();
                Methods::pauseProgram();
                break;
            case '2':
                system("cls");
                personalMoneyTracker.addExpense();
                Methods::pauseProgram();
                break;
            case '3':
                system("cls");
                personalMoneyTracker.displayCurrentMonthBalance();
                Methods::pauseProgram();
                break;
            case '4':
                system("cls");
                personalMoneyTracker.displayPreviousMonthBalance();
                Methods::pauseProgram();
                break;
            case '5':
                system("cls");
                personalMoneyTracker.displayPeriodBalance();
                Methods::pauseProgram();
                break;
            case '6':
                system("cls");
                personalMoneyTracker.changePassword();
                Methods::pauseProgram();
                break;
            case '7':
                system("cls");
                personalMoneyTracker.logout();
                Methods::pauseProgram();
                break;
            default:
                cout << "Cos poszlo nie tak!" << endl;
                exit(0);
            }
        }
    }
    return 0;
}
