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
    int account_id;
    int money;
    char *name;

public:
    Account(int ini_money, int number, char *in_name) : money(ini_money), account_id(number)
    {
        int len = strlen(in_name);
        name = new char[len + 1];
        strcpy(name, in_name);
    }
    Account(const Account &copy) : account_id(copy.account_id), money(copy.money)
    {
        int copy_len = strlen(copy.name);
        this->name = new char[copy_len + 1];
        strcpy(this->name, copy.name);
    }
    int Getmoney() const
    {
        return money;
    }
    int GetaccountId() const
    {
        return account_id;
    }
    int Deposit(const int p_money)
    {
        this->money += p_money;
        cout << "balance:" << Getmoney() << endl;
    }

    bool Withdraw(const int p_money)
    {
        if (p_money > this->money)
        {
            cout << "not enough the money!" << endl;
            return false;
        }
        else
        {
            this->money -= p_money;
            cout << "balance" << Getmoney() << endl;
            return true;
        }
    }

    void ShowInfo() const
    {
        cout << "customer name:" << this->name << endl;
        cout << "account number:" << GetaccountId() << endl;
        cout << "balance:" << Getmoney() << endl;
    }
    ~Account()
    {
        delete[] name;
    }
};

class AccountHandler
{
private:
    Account *customer[MAX_CUSTOMER];
    int account_index;

public:
    AccountHandler() : account_index(0) {}
    void ShowMenu()
    {
        cout << "---- menu ----" << endl;
        cout << "1.new account" << endl;
        cout << "2.deposit" << endl;
        cout << "3.withdraw" << endl;
        cout << "4.Show All infomation" << endl;
        cout << "0. exit" << endl;
        cout << "--------------" << endl;
    }
    void MakeNewAccount()
    {
        char t_name[MAX_NAME];
        int first_deposit;
        int t_accountnumber;
        char c_answer;
        cout << "--------------" << endl;
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
    bool YesOrNo(const char answer)
    {
        if (answer == 'Y')
            return true;
        else if (answer == 'F')
            return false;
        else
            return false;
    }
    void ShowAllInfo()
    {
        for (int i = 0; i < account_index; i++)
            customer[i]->ShowInfo();
    }
    void DepositMoney()
    {
        int id;
        int deposit_money;
        cout << "--------------" << endl;
        cout << "write your AccountID:";
        cin >> id;
        for (int i = 0; i < account_index; i++)
        {
            if (id == customer[i]->GetaccountId())
            {
                cout << "write deposit amount:";
                cin >> deposit_money;
                customer[i]->Deposit(deposit_money);
                cout << "deposit success!" << endl;
                break;
            }
            else
            {
                cout << "fail search accountID" << endl;
            }
        }
    }
    void WithdrawMoney()
    {
        int id;
        int i;
        int withdraw_money;
        cout << "--------------" << endl;

        cout << "write your Account ID:";
        cin >> id;
        for (i = 0; i < this->account_index; i++)
        {
            if (id == customer[i]->GetaccountId())
            {
                cout << "write withdraw amount:";
                cin >> withdraw_money;
                if (customer[i]->Withdraw(withdraw_money) == true)
                {
                    cout << "withdraw success!" << endl;
                    break;
                }
            }
        }
        if (i >= this->account_index)
        {
            cout << "fail search accountID!" << endl;
        }
    }

    int GetAccountIndex() const
    {
        return account_index;
    }

    ~AccountHandler()
    {
        for (int i = 0; i < account_index; i++)
            delete customer[i];
    }
};

int main()
{
    AccountHandler manager;
    int menu;
    bool running = true;
    while (running == true)
    {
        manager.ShowMenu();
        cout << "select number:";
        cin >> menu;
        switch (menu)
        {
        case MAKE:
            if (manager.GetAccountIndex() > MAX_CUSTOMER)
            {
                cout << "bank is full!" << endl;
                break;
            }
            else
            {
                manager.MakeNewAccount();
                break;
            }
            break;
        case DEPO:
            manager.DepositMoney();
            break;
        case WITH:
            manager.WithdrawMoney();
            break;
        case SHOW:
            manager.ShowAllInfo();
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

    return 0;
}
