#include "Acc.h"

/*void Account::set_recv_mess(string mess, int id_sender)
{
	Message tmp(mess, id_sender, my_id);
	recv_mess.push_back(tmp);
}

void Account::set_send_mess(string mess, int id_recver)
{
	Message tmp(mess, my_id, id_recver);
	send_mess.push_back(tmp);
}

void Account::print_all_send_massage()
{
	for (int i = 0; i < send_mess.size(); ++i)
	{
		cout << "id recipient = " << send_mess[i].get_id_recv() << "  msg: " << send_mess[i].get_mess() << endl;
	}
}

void Account::print_recv_massage()
{
	for (int i = 0; i < recv_mess.size(); ++i)
	{
		cout << "id sender = " << recv_mess[i].get_id_send() << "  msg: " << recv_mess[i].get_mess() << endl;
	}
}*/
void Account::set_recv_mess(string mess, string name_sender)
{
	Message tmp(mess, name_sender, _name);
	recv_mess.push_back(tmp);
}

void Account::set_send_mess(string mess, string name_recver)
{
	Message tmp(mess, _name, name_recver);
	send_mess.push_back(tmp);
}

void Account::print_all_send_massage()
{
	for (int i = 0; i < send_mess.size(); ++i)
	{
		cout << "Name recipient = " << send_mess[i].get_name_recv() << "  msg: " << send_mess[i].get_mess() << endl;
	}
}

void Account::print_recv_massage()
{
	for (int i = 0; i < recv_mess.size(); ++i)
	{
		cout << "Name sender = " << recv_mess[i].get_name_send() << "  msg: " << recv_mess[i].get_mess() << endl;
	}
}
bool Accounts_data::containsLog(string login) //func for checking are loging already in use or no

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

int Accounts_data::get_id_by_login(string login)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i].get_login() == login)
		{
			return i;
		}
	}

	return (-1);
}

int Accounts_data::get_id_by_name(string name)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i].get_name() == name)
		{
			return i;
		}
	}

	return (-1);
}