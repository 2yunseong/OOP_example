#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
#pragma once

class MyFriendInfo
{
private:
	char *fname;
	int fage;
public:
	MyFriendInfo(char* s_name, int s_age);
	void ShowInfo() const;
	~MyFriendInfo()
	{
		delete[]fname;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(char input_name[], int input_age, char input_address[], char input_phone[]);

	void ShowMyFriendAllData() const;
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
};