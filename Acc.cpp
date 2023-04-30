#include "Acc.h"

bool Accounts_data::containsLog(string login) //����� ���� �������� ��������� ����, ����� � ������ ��������� ����� ��������� ��� � ���
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

string Account::srm()
{
		for (int i = 0; i < crm; i++)
		{
			cout << received_message[i] << endl;
		}
}

string Account::ssm()
{
	for (int i = 0; i < csm; i++)
	{
		cout << sent_message[i] << endl;
	}
}
