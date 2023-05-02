#include <iostream>

#include "Acc.h"
struct for_menu // structure to return value from menu
{
	int id = -1;  // we know who logged in
	bool res = false; // this is if selection error \ number of inputs exceeded \ just exit
};

for_menu login_menu(Accounts_data& accs);
bool chat_menu(Accounts_data& accs, int id);



int main()
{
	setlocale(LC_ALL, "rus");

	Accounts_data accs; // ALL logins and their passwords will be stored here

	cout << "---------------------------------------" << endl;
	cout << "	Welcome to the chat app! " << endl;
	cout << "---------------------------------------\n" << endl;

	while (true)
	{
		// Launching the login menu
		for_menu rezult = login_menu(accs);  // в переменной rezult храним id пользователя, который залогинился успешно
		if (!rezult.res) break;	// if you exited the function with false, then exit the while loop and end the program

		// Launching the chat menu
		if (chat_menu(accs, rezult.id)) break;		// if you left the function with false, then exit the while loop
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
			if (accs.containsLog(tmp))         //login busy test
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
			if (tmp.size() > 5) // password longer than 5 characters
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
			if (accs.containsName(tmp))         //occupancy test name
			{
				cout << "Name is busy\n";
			}
			else
			{
				acc.set_name(tmp);
				acc.set_my_id(accs.count_acc());
				cout << "Account created!\n";
				break;
			}
		}
		accs.add_acc(acc); //added the created account
	}
	case '2':
	{
		if (accs.count_acc() == 0) // if there is no account, then we will ask you to restart the chat and create an account
		{
			cout << "There is not a single registration! Re-enter the chat and create an account!" << endl;
			return rezult; // closed the chat, analog input q
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


bool chat_menu(Accounts_data& accs, int id) // ÍÅÎÁÕÎÄÈÌÎ ÑÄÅËÀÒÜ!
{
	while (true)
	{
		cout << "Select one of following actions: " << endl
			<< "1 - View received messages " << endl
			<< "2 - View sent messages " << endl
			<< "3 - Write a new letter " << endl
			<< "4 - Write a new letter to all members of chat " << endl
			<< "q - Sign out" << endl;

		char choice;
		cin >> choice;
		if (choice == 'q')
		{
			cout << "You are logged out " << accs[id].get_name() << endl;
			return false;
		}

		switch (choice)
		{
		case '1':
		{

			cout << "You have received the following messages: " << endl;
			accs[id].print_recv_massage();
			break;
		}
		case '2':
		{
			cout << "You sent the following messages: " << endl;
			accs[id].print_all_send_massage();
			break;
		}
		case '3':
		{
			string receiver;
			while (true)
			{
				cout << "Enter the username you want to write to: " << endl; // user names and logins are not repeated, so we can send either by login or by account name (we send by name)
				cin >> receiver;
				if (accs.containsName(receiver))         //occupancy test name
				{
					string msg; //message
					cout << "Enter you massage: " << endl;
					getline(cin, msg);
					getline(cin, msg);  //if write "getline" only one time it's working incorrectly(displays all text except the first word)

					// find out id
					int id_recver = accs.get_id_by_name(receiver);

					// save in received from the recipient
					accs[id_recver].set_recv_mess(msg, accs[id].get_name());

					// save in sent from the sender
					accs[id].set_send_mess(msg, receiver);

					break;
				}
				else
				{
					cout << "user with this name not found\n";
				}
			}
			break;
		}
		case '4':
		{
			string msg; //message
			cout << "Enter you massage: " << endl;
			getline(cin, msg);
			getline(cin, msg);
			for (int i = 0; i < accs.count_acc(); i++) //entering the message into the database for each recipient
			{
				accs[i].set_recv_mess(msg, accs[id].get_name());
			}
			for (int i = 0; i < accs.count_acc(); i++) //entering the message into the database for sender
			{
				accs[id].set_send_mess(msg, accs[i].get_name());
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
