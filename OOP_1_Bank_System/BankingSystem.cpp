#include <iostream>
#include <cstring>
#define MAX_CUSTOMER 20
#define MAX_NAME 15

enum
{
    MAKE = 1,
    DEPO = 2,
    WITH = 3,
    SHOW = 4,
    EXIT = 0
};
using namespace std;
class Account
{
private:
    int accountnum;
    int money;
    char *name;

public:
    Account(int ini_money, int number, char *in_name) : money(ini_money), accountnum(number)
    {
        int len = strlen(in_name);
        name = new char[len + 1];
        strcpy(name, in_name);
    }
    int Getmoney() const
    {
        return money;
    }
    int Getaccountnum() const
    {
        return accountnum;
    }
    int Deposit(int p_money)
    {
        money += p_money;
        cout << "balance" << Getmoney();
    }

    int Withdraw(int p_money)
    {
        money -= p_money;
        cout << "balance" << Getmoney();
    }

    void ShowInfo() const
    {
        cout << "customer name:" << name<<endl;
        cout << "account number:" << Getaccountnum()<<endl;
        cout << "balance:" << Getmoney()<<endl;
    }
    ~Account()
    {
        delete[] name;
    }
};
Account *customer[MAX_CUSTOMER];
int account_index = 0;
bool YesOrNo(const char answer)
{
    if (answer == 'Y')
        return true;
    if (answer == 'F')
        return false;
}
void MakeNewAccount()
{
    char t_name[MAX_NAME];
    int first_deposit;
    int t_accountnumber;
    char c_answer;
    cout << "write your first name:";
    cin >> t_name;
    cout << "set account number:";
    cin >> t_accountnumber;
    cout << "have you deposit money? (Y/F)";
    cin >> c_answer;
    if (YesOrNo(c_answer) == true)
    {
        cout << "write amount:";
        cin >> first_deposit;
        customer[account_index++] = new Account(first_deposit, t_accountnumber, t_name);
        cout << "make success!" << endl;
    }
    else if (YesOrNo(c_answer) == false)
    {
        first_deposit = 0;
        customer[account_index++] = new Account(first_deposit, t_accountnumber, t_name);
        cout << "make success!" << endl;
    }
    else
    {
        cout << "Fail access!" << endl;
    }
}

void ShowMenu()
{
    cout << "--- menu ---" << endl;
    cout << "1.new account" << endl;
    cout << "2.deposit" << endl;
    cout << "3.withdraw" << endl;
    cout << "4.Show All infomation" << endl;
    cout << "0. exit" << endl;
}

void ShowAllInfo()
{
    for (int i = 0; i < account_index; i++)
        customer[i]->ShowInfo();
}
int main()
{
    int menu;
    bool running = true;
    while (running == true)
    {
        ShowMenu();
        cout << "select number:";
        cin >> menu;
        switch (menu)
        {
        case MAKE:
            if (account_index > MAX_CUSTOMER)
            {
                cout << "bank is full!" << endl;
                break;
            }
            else
            {
                MakeNewAccount();
                break;
            }
            break;
        case DEPO:
            break;
        case WITH:
            break;
        case SHOW:
            ShowAllInfo();
            break;
        case EXIT:
            cout << "program exit." << endl;
            running = false;
            break;
        default:
            cout << "access fail!" << endl;
            break;
        }
    }
}
