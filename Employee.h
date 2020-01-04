#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

#pragma once
#define MAX_WORKER 50

class Employee
{
private:
	char name[50];
public:
	Employee(char *e_name);
	void ShowEmployeeName() const;
	~Employee(){}
};

class PermanentWorker : public Employee
{
private:
	int salary;		//month pay.
public:
	PermanentWorker(char *e_name,int money);
	int GetPay() const;
	void ShowSalaryInfo() const;
	~PermanentWorker(){}
};

class Employeehandler
{
private:	Employee* emplist[MAX_WORKER];
	int empNum;
public:
	Employeehandler();
	void AddEmployee(Employee* emp);
	void ShowAllSalaryInfo();
	void ShowTotalSalary();
	~Employeehandler(){}
};

class TemporaryWorker : public Employee
{
private:
	int worktime;		
	int payperhour;		
	/* salary = worktime X payperhour */
public:
	TemporaryWorker(char*e_name, int pay);
	void AddTime(int time);
	int GetPay() const;
	void ShowSalaryInfo()const;
};

class SalesWorker : public PermanentWorker
{
private:
	int sale_result;
	double bonus_ratio;
public:
	SalesWorker(char*e_name, int money, int result, double ratio);

};
