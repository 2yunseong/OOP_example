#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

#pragma once
#define MAX_WORKER 50

class Jung		//pernament worker 
{
private:

	char name[100];
	int salary;
public:
	Jung(char* name, int money);
	int GetPay() const;
	void ShowSalaryInfo() const;
	~Jung(){}
};
