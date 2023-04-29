#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
public:
	Account(string name, string login, string password);
	Account(string login, string password);

	string get_name() { return _name; }
	string get_login() { return _login; }
	string get_password() { return _password; }

protected:
	string _name;
	string _login;
	string _password;
};

class Accounts_data
{
public:
	Accounts_data()
	{
		count = 0;
	}

	inline int count_acc() { return count; }
	void add_acc(Account new_acc)
	{
		count++;
		data.push_back(new_acc);
	}

	//void rem_acc(); // ���� �� �����, �� �� �������

	bool containsLog(string login); // ��������, ������� ����� ������� ��� ���

	bool containsName(string name);

	bool containsPassword(string password);

	Account get_acc(); //TO DO

protected:
	int count; // ���������� ���������� ���������
	vector<Account> data;
};

