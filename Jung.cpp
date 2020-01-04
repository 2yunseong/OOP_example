#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
#include "Jung.h"

Jung::Jung(char* name, int money)
	:salary(money)
{
	strcpy(this->name, name);
}

int Jung::GetPay() const
{
	return salary;
}

void Jung::ShowSalaryInfo() const
{
	cout << "name:" << this->name << endl;
	cout << "salary:" << this->salary << endl;
}

