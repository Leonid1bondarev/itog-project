#include <iostream>

#include "Acc.h"

//using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//Класс аккаунтЫ
	Accounts_data accs; // тут будут храниться ВСЕ логины и их пароли
	/*cout << "Count accs: " << accs.count_acc() << endl; //вывод количества имеющихся логинов

	Account first_acc("Evgen", "strelok", "QWE123rt"); // зарегали первый акк
	Account second_acc("Leonid", "voin", "asdf453");	// зарегали второй акк

	cout << first_acc.get_login() << endl;				//вывод логина из первого аккаунта

	accs.add_acc(first_acc);		//добавили первый акк в базу
	accs.add_acc(second_acc);		//добавили второй акк в базу

	cout << "Count accs: " << accs.count_acc() << endl;	//вывод количества имеющихся логинов

	if (accs.contains("voin")) cout << "Login is busy\n";		//тест проверки на занятость логина
	else cout << "Login is free\n";

	if (accs.contains("strelok")) cout << "Login is busy\n";	//тест проверки на занятость логина
	else cout << "Login is free\n";

	if (accs.contains("voin123")) cout << "Login is busy\n";	//тест проверки на занятость логина
	else cout << "Login is free\n";

	//Класс данные чата
	//TO DO
	*/
	string login, password, name; //данные аккаунта(вынесены за цикл для того, чтобы видеть их в любой части кода)


	cout << "Добро пожаловать в итоговый проект первого модуля, приложение чат!" << endl;
	while (true)
	{
		cout << "Выберите один из вариантов" << endl
			<< "1 - зарегестрироваться" << endl
			<< "2 - войти в аккаунт" << endl
			<< "q - чтобы выйти из программы" << endl;
		char choice;
		cin >> choice;
		if (choice == 'q')
		{
			break;
		}
		switch (choice)
		{
		case '1':
			while (true)
			{
				cout << "Введите логин для вашего аккаунта: " << endl;
				cin >> login;
				if (accs.containsLog(login))         //тест проверки на занятость логина
				{
					cout << "Login is busy\n";
				}
				else
				{
					cout << "Login is free\n";
					break;
				}
			}
				cout << "Введите пароль для вашего аккаунта: " << endl;
				cin >> password;
				while (true)
				{
					cout << "Придумайте имя для вашего аккаунта" << endl;  
					cin >> name;
					if (accs.containsName(name))         //тест проверки на занятость name
					{
						cout << "Name is busy\n";
					}
					else
					{
						cout << "Name is free\n";
						break;
					}
				}
				//Account first_acc(name, login, password);       //надо попробовать уместить это здесь
				//accs.add_acc(first_acc); //занесли созданный аккаунт
			break;
		case '2':
			while (true)
			{
				cout << "Введите логин для вашего аккаунта: " << endl;
				cin >> login;
				if (accs.containsLog(login))      /*тест, проверяющий наличие логина в базе, цикл замкнут и если аккаунтов ещё нет,
					то надо придумать как этот цикл закрыть*/
				{
					break;
				}
				else
				{
					cout << "Wrong login\n";
				}
			}
			while (true)
			{
				cout << "Введите пароль для вашего аккаунта: " << endl;
				cin >> password;
				if (accs.containsPassword(password))         //тест проверки на занятость логина
				{
					break;
				}
				else
				{
					cout << "Wrong password\n";
				}
			}
			//name = _name; // приравниваем имя аккаунта, которое будет отображаться в программе к имени акканта(для строчки кода,
			//которая отображает имя аккаунта, в который мы вошли)
			break;
		default:
			cout << "Неправильно указан оператор" << endl;
			break;
		}
		cout << "Вы вошли в аккаунт " << name << endl;


		Account first_acc(name, login, password);     /*создали класс для созданного аккаунта(вообще это должно быть после первого кейса,
		но если засунуть это туда сразу, то выдаёт ошибку, но работает и так, просто выглядит как-то неправильно*/


		accs.add_acc(first_acc); //занесли созданный аккаунт

		while (true)
		{
			cout << "Выберите одно из перечисленных действий: " << endl
				<< "1 - посмотреть полученные сообщения" << endl
				<< "2 - посмотреть отправленные сообщения" << endl
				<< "3 - написать новое письмо" << endl
				<< "q - чтобы выйти из аккаунта" << endl;
			char choice2;
			cin >> choice2;
			if (choice2 == 'q')
			{
				cout << "Вы вышли из аккаунта " << name << endl;
				break;
			}
			switch (choice2)
			{
			case '1':
				cout << "Вы получили следующие сообщения: " << endl;

				break;
			case '2':
				cout << "Вы отправили следующие сообщения: " << endl;
				break;
			case '3':
				string receiver;
				while (true)
				{
					cout << "Введите имя пользователя, которому вы хотите написать: " << endl;
					cin >> receiver;
					if (accs.containsName(receiver))         //тест проверки на занятость name
					{
						//добавить реализацию функции отправки сообщения
						break;
					}
					else
					{
						cout << "пользователь с таким именем не найден\n";
					}
				}
				break;
			default:
				cout << "Неправильно указан оператор" << endl;
				break;
			}
		}
		
	}

	return 0;
}