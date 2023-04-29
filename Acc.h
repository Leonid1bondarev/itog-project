#pragma once
#include <iostream>
#include <string>
using namespace std;
class account
{
public:
	account(string name, string login, string password);
	account(string login, string password);
protected:
	string _name;
	string _login;
	string _password;
};
