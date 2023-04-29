#include "Acc.h"

Account::Account(string name, string login, string password) : _name(name), _login(login), _password(password)
{

}

Account::Account(string login, string password) : _login(login), _password(password)
{

}

bool Accounts_data::contains(string login)
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
