#include <iostream>

#include "Acc.h"

//using namespace std;

struct for_menu // ��������� ��� �������� �������� �� ����
{
	int id = -1;  // �� ����� ��� ����������� 
	bool res = false; // ��� ���� ������ ������ \ ��������� ���������� ������ \ ������ �����
};

for_menu login_menu(Accounts_data& accs);
bool chat_menu(Accounts_data& accs, int id);



int main()
{
	setlocale(LC_ALL, "rus");

	Accounts_data accs; // ��� ����� ��������� ��� ������ � �� ������

	cout << "---------------------------------------" << endl;
	cout << "	Welcome to the chat app! " << endl;
	cout << "---------------------------------------\n" << endl;

	while (true)
	{
		// ������ ���� ������
		for_menu rezult = login_menu(accs);  // � ���������� rezult ������ id ������������, ������� ����������� �������
		if (!rezult.res) break;	// ���� ����� �� ������� � false, �� ����� �� ����� while � ��������� �����

		// ������ ���� ����
		if (chat_menu(accs, rezult.id)) break;		// ���� ����� �� ������� � false, �� ����� �� ����� while

	}

	return 0;
}

for_menu login_menu(Accounts_data& accs)
{
	for_menu rezult;

	cout << " Make a choice: " << endl
		<< "	1 - registration" << endl
		<< "	2 - log in to your account" << endl
		<< "	q - exit the chat " << endl;

	char choice;
	cin >> choice;
	if (choice == 'q')
	{
		return rezult;
	}

	switch (choice)
	{
	case '1':
	{
		Account acc;
		string tmp;

		while (true)
		{
			cout << "Enter the login for your account: " << endl;
			cin >> tmp;
			if (accs.containsLog(tmp))         //���� �������� �� ��������� ������
			{
				cout << "Login is busy\n";
			}
			else
			{
				acc.set_login(tmp);
				cout << "Login created!\n";
				break;
			}
		}

		cout << "Enter the password for your account: " << endl;
		while (true)
		{
			cin >> tmp;
			if (tmp.size() > 5) // ������ ������ 5 ��������
			{
				acc.set_password(tmp);
				break;
			}
			else
			{
				cout << "Enter a password longer than 5 symbols!" << endl;
			}
		}

		while (true)
		{
			cout << "Come up with a name for your account: " << endl;
			cin >> tmp;
			if (accs.containsName(tmp))         //���� �������� �� ��������� name
			{
				cout << "Name is busy\n";
			}
			else
			{
				acc.set_name(tmp);
				cout << "Account created!\n";
				break;
			}
		}

		accs.add_acc(acc); //������� ��������� �������

		//break; // ��� ����� �� �����, �� �� ������� �������, ������ ���� ����������, �.�. � ����� ����
	}
	case '2':
	{
		if (accs.count_acc() == 0) // ���� ��� �� ������ ��������, �� �������� ������������� ��� � ������� �������
		{
			cout << "There is not a single registration! Re-enter the chat and create an account!" << endl;
			return rezult; // ������� ���, ������ ����� q
		}

		string tmp;
		int attempt = 2;
		int id;

		while (true)
		{
			cout << "Enter login: " << endl;
			cin >> tmp;
			if (accs.containsLog(tmp))
			{
				id = accs.get_id_by_login(tmp);
				cout << "Hello, " << accs[id].get_name() << "!\n Enter password: \n";
				break;
			}
			else
			{
				if (attempt == 0) return rezult;
				cout << "Wrong login! There are still attempts left: " << attempt-- << endl;
			}
		}

		attempt = 2;
		while (true)
		{
			cin >> tmp;
			if (tmp == accs[id].get_password())
			{
				rezult.id = id;
				rezult.res = true;
				cout << "Authentication was successful!" << endl;
				break;
			}
			else
			{
				if (attempt == 0) return rezult;
				cout << "Wrong password! There are still attempts left: " << attempt-- << endl;
			}
		}
		break;
	}
	default:
	{
		cout << "Wrong choice" << endl;
		break;
	}
	}

	return rezult;
}


bool chat_menu(Accounts_data& accs, int id) // ���������� �������!
{
	while (true)
	{
		cout << "Select one of following actions: " << endl
			<< "1 - View received messages " << endl
			<< "2 - View sent messages " << endl
			<< "3 - Write a new letter " << endl
			<< "q - Sign out" << endl;

		char choice;
		cin >> choice;
		if (choice == 'q')
		{
			cout << "You are logged out " << accs[id].get_name() << endl;
			return false;
			//break;
		}

		switch (choice)
		{
		case '1':
		{

			cout << "You have received the following messages: " << endl;
			//put srm
			break;
		}
		case '2':
		{
			cout << "You sent the following messages: " << endl;
			//put ssm
			break;
		}
		case '3':
		{
			string receiver;
			while (true)
			{
				cout << "Enter the username you want to write to: " << endl;
				cin >> receiver;
				if (accs.containsName(receiver))         //occupancy test name
				{
					//add add_sm for this acc and add_rm for reciever
					break;
				}
				else
				{
					cout << "user with this name not found\n";
				}
			}
			break;
		}
		default:
		{
			cout << "Operator specified incorrectly" << endl;
			break;
		}
		}
	}

	return true;
}