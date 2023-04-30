#include <iostream>

#include "Acc.h"

//using namespace std;

struct for_menu // структура для возврата значения из меню
{
	int id = -1;  // мы знаем кто залогинился 
	bool res = false; // это если ошибка выбора \ превышено количество вводов \ просто выход
};

for_menu login_menu(Accounts_data& accs);
bool chat_menu(Accounts_data& accs, int id);



int main()
{
	setlocale(LC_ALL, "rus");

	Accounts_data accs; // тут будут храниться ВСЕ логины и их пароли

	cout << "---------------------------------------" << endl;
	cout << "	Welcome to the chat app! " << endl;
	cout << "---------------------------------------\n" << endl;

	while (true)
	{
		// Запуск меню логина
		for_menu rezult = login_menu(accs);  // в переменной rezult храним id пользователя, который залогинился успешно
		if (!rezult.res) break;	// если вышли из функции с false, то выйти из цикла while и завершить прогу

		// Запуск меню чата
		if (chat_menu(accs, rezult.id)) break;		// если вышли из функции с false, то выйти из цикла while

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
			if (accs.containsLog(tmp))         //тест проверки на занятость логина
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
			if (tmp.size() > 5) // пароль длинее 5 символов
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
			if (accs.containsName(tmp))         //тест проверки на занятость name
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

		accs.add_acc(acc); //занесли созданный аккаунт

		//break; // тут брэйк не нужен, мы же создали аккаунт, теперь идем логиниться, т.е. в некст кейз
	}
	case '2':
	{
		if (accs.count_acc() == 0) // если нет ни одного аккаунта, то попросим перезапустить чат и создать аккаунт
		{
			cout << "There is not a single registration! Re-enter the chat and create an account!" << endl;
			return rezult; // закрыли чат, аналог ввода q
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


bool chat_menu(Accounts_data& accs, int id) // НЕОБХОДИМО СДЕЛАТЬ!
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