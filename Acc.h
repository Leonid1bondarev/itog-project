#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
public:
	Account() : _name(""), _login(""), _password("") {}
	//Account(string name, string login, string password);
	//Account(string login, string password);

	string get_name() { return _name; }
	string get_login() { return _login; }
	string get_password() { return _password; }

	void set_name(string name)			{ _name = name; }
	void set_login(string login)		{ _login = login; }
	void set_password(string password)	{ _password = password; }

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

	bool containsLog(string login); // проверка, зареган такой аккаунт или нет
	int get_id_by_login(string login); // id этого логина (номер)

	bool containsName(string name);

	Account operator[](int i) { return data[i]; }

protected:
	int count; // количество имиеющихся аккаунтов
	vector<Account> data;
};

