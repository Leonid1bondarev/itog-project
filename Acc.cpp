#include "Acc.h"

Account::Account(string name, string login, string password) : _name(name), _login(login), _password(password)
{

}

Account::Account(string login, string password) : _login(login), _password(password)
{

}

bool Accounts_data::containsLog(string login) //можно сюда добавить вложенный цикл, чтобы в каждой иттерации цикла проверять ещё и имя
{
	bool rezult = false;

	for (int i = 0; i < count; ++i)
	{
		if (data[i].get_login() == login)
		{
			rezult = true;
			break;
		}
	}
	return rezult;
}

bool Accounts_data::containsName(string name)
{
	bool rezult = false;

	for (int i = 0; i < count; ++i)
	{
		if (data[i].get_name() == name)
		{
			rezult = true;
			break;
		}
	}
	return rezult;
}

bool Accounts_data::containsPassword(string password)
{
	bool rezult = false;

	for (int i = 0; i < count; ++i)
	{
		if (data[i].get_password() == password)
		{
			rezult = true;
			break;
		}
	}
	return rezult;
}
