#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
#include "MyFriend.h"

MyFriendInfo::MyFriendInfo(char* s_name, int s_age)
	:fage(s_age)
{
	int len = strlen(s_name) + 1;
	fname = new char[len];
	strcpy(fname, s_name);
}
void MyFriendInfo::ShowInfo() const
{
	cout << "name:" << this->fname << endl;
	cout << "age :" << this->fage << endl;
}

MyFriendDetailInfo::MyFriendDetailInfo(char input_name[], int input_age, char input_address[], char input_phone[])
	:MyFriendInfo(input_name, input_age)
{
	int address_len = strlen(input_address) + 1;
	int phone_len = strlen(input_phone) + 1;
	addr = new char[address_len];
	phone = new char[phone_len];
	strcpy(addr, input_address);
	strcpy(phone, input_phone);
}

void MyFriendDetailInfo::ShowMyFriendAllData() const
{
	ShowInfo();
	cout << "address:" << addr << endl;
	cout << "phone Num:" << phone << endl;
}