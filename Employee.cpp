#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
#include "Employee.h"

/* method Employee */

Employee::Employee(char *e_name)
{
	strcpy(this->name, e_name);
}

void Employee::ShowEmployeeName() const
{
	cout << "name" << this->name << endl;
}

/* method permanent Worker */

PermanentWorker::PermanentWorker(char *e_name, int money)
	:salary(money), Employee(e_name)
{}

int PermanentWorker::GetPay() const
{
	return salary;
}

void PermanentWorker::ShowSalaryInfo() const
{
	ShowEmployeeName();
	cout << "salary:" << this->salary << endl;
}

/* method Employee handler */

Employeehandler::Employeehandler() :empNum(0) {}

void Employeehandler::AddEmployee(Employee* emp)
{
	emplist[empNum++] = emp;
}

void Employeehandler::ShowAllSalaryInfo()
{
	/*for (int i = 0; i < empNum; i++)
		emplist[i]->ShowSalaryInfo();*/
}

void Employeehandler::ShowTotalSalary()
{
	int sum = 0;
	/*for (int i = 0; i < empNum; i++)
		sum += emplist[i]->GetPay();*/
	cout << "salary Sum: " << sum << endl;
}

/*method Temporary Worker*/

TemporaryWorker::TemporaryWorker(char * e_name, int pay)
	:Employee(e_name),worktime(0), payperhour(pay){}

void TemporaryWorker::AddTime(int time)
{
	worktime += time;
}

int TemporaryWorker::GetPay() const
{
	return worktime*payperhour;
}

void TemporaryWorker::ShowSalaryInfo() const
{
	ShowEmployeeName();
	cout << "pay" << GetPay() << endl;
}

/* method Sales worker */

SalesWorker::SalesWorker(char * e_name, int money, int result, double ratio)
{
}
