#include <iostream>
#include <cstring>

// start at 336p , EmployeeManager3.cpp (clear)
// repeat overriding, and virtual function !!	(clear)
//in visual studio, why error in class parameter [char*] sending
using namespace std;
namespace RISK_LEVEL
{
enum
{
	RISK_A = 3,
	RISK_B = 2,
	RISK_C = 1
};
}

class Employee
{
private:
	char name[100];

public:
	Employee(char *name) //maybe this syntax error in vs.
	{
		strcpy(this->name, name);
	}
	virtual void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;			 //pure virtual function. abstract class.
	virtual void ShowSalaryInfo() const = 0; //pure virtual function. abstract class.
};

class PermanentWorker : public Employee
{
private:
	int salary; //permanetntWorker's Pay
public:
	PermanentWorker(char *name, int money)
		: Employee(name), salary(money) //name is member variable of Employee.
	{
	}
	int GetPay() const //This Function is Get PermanentWorker's Pay
	{				   //virtual func.
		return salary;
	}
	void ShowSalaryInfo() const //virtual func. and override.
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int worktime;
	int pay_per_hour;

public:
	TemporaryWorker(char *name, int pay)
		: Employee(name), worktime(0), pay_per_hour(pay)
	{
	}
	void AddWorkTime(int time)
	{
		worktime += time;
	}
	int GetPay() const
	{
		return worktime * pay_per_hour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int sales_result;
	double bonus_ratio;

public:
	SalesWorker(char *name, int money, double ratio)
		: PermanentWorker(name, money), sales_result(0), bonus_ratio(ratio)
	{
	}
	void AddSalesResult(int value)
	{
		sales_result += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(sales_result * bonus_ratio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary: " << GetPay() << endl;
	}
};

// class ForeignSalesWorker : public SalesWorker
// {
// private:
// 	const int risk;

// public:
// 	ForeignSalesWorker(char *name, int money, double ratio, int risk_lev)
// 		: SalesWorker(name, money, ratio), risk(risk_lev)
// 	{
// 	}
// 	int GetPay() const
// 	{
// 		switch (risk)
// 		{
// 		case RISK_LEVEL::RISK_A:
// 			return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_A * 0.1);
// 			break;
// 		case RISK_LEVEL::RISK_B:
// 			return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_B * 0.1);
// 			break;
// 		case RISK_LEVEL::RISK_C:
// 			return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_C * 0.1);
// 			break;
// 		}
// 	}
// 	void ShowSalaryInfo() const
// 	{
// 		ShowYourName();
// 		cout << "Salary:" << SalesWorker::GetPay() << endl;
// 		switch (risk)
// 		{
// 		case RISK_LEVEL::RISK_A:
// 			cout << "risk pay:" << (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_A * 0.1) << endl;
// 			break;
// 		case RISK_LEVEL::RISK_B:
// 			cout << "risk pay:" << (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_B * 0.1) << endl;
// 			break;
// 		case RISK_LEVEL::RISK_C:
// 			cout << "risk pay:" << (int)(SalesWorker::GetPay() * RISK_LEVEL::RISK_C * 0.1) << endl;
// 			break;
// 		}
// 		cout << "Sum: " << GetPay() << endl;
// 	}
// };
class EmployeeHandler //control class
{
private:
	Employee *empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{
	}
	void AddEmployee(Employee *emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary Sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	//create object control class
	EmployeeHandler handler;

	//register permanentWorker
	handler.AddEmployee(new PermanentWorker("kim", 1000));
	handler.AddEmployee(new PermanentWorker("lee", 2300));

	//register TemporaryWorker
	TemporaryWorker *alba = new TemporaryWorker("yoon", 700);
	alba->AddWorkTime(50);
	handler.AddEmployee(alba);

	//register SalesWorker
	SalesWorker *seller = new SalesWorker("park", 2000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	//register ForeignsalesWorker

	// ForeignSalesWorker *foreign_seller("gang", 4500, 0.1, 3);
	// ForeignSalesWorker *foreign_seller_2("An", 4500, 0.1, 2);
	// ForeignSalesWorker *foreign_seller_3("Choi", 4500, 0.1, 1);

	// foreign_seller->AddSalesResult(3000);
	// foreign_seller_2->AddSalesResult(3000);
	// foreign_seller_3->AddSalesResult(3000);

	// handler.AddEmployee(foreign_seller);
	// handler.AddEmployee(foreign_seller_2);
	// handler.AddEmployee(foreign_seller_3);
	//infomation of Pay on this month
	handler.ShowAllSalaryInfo();

	//infomation of Total Pay on this month
	handler.ShowTotalSalary();

	return 0;
}
