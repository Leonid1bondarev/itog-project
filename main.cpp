#include <iostream>

#include "Acc.h"

//using namespace std;

struct for_menu // ñòðóêòóðà äëÿ âîçâðàòà çíà÷åíèÿ èç ìåíþ
{
	int id = -1;  // ìû çíàåì êòî çàëîãèíèëñÿ 
	bool res = false; // ýòî åñëè îøèáêà âûáîðà \ ïðåâûøåíî êîëè÷åñòâî ââîäîâ \ ïðîñòî âûõîä
};

for_menu login_menu(Accounts_data& accs);
bool chat_menu(Accounts_data& accs, int id);



int main()
{
	setlocale(LC_ALL, "rus");

	Accounts_data accs; // òóò áóäóò õðàíèòüñÿ ÂÑÅ ëîãèíû è èõ ïàðîëè

	cout << "---------------------------------------" << endl;
	cout << "	Welcome to the chat app! " << endl;
	cout << "---------------------------------------\n" << endl;

	while (true)
	{
		// Çàïóñê ìåíþ ëîãèíà
		for_menu rezult = login_menu(accs);  // â ïåðåìåííîé rezult õðàíèì id ïîëüçîâàòåëÿ, êîòîðûé çàëîãèíèëñÿ óñïåøíî
		if (!rezult.res) break;	// åñëè âûøëè èç ôóíêöèè ñ false, òî âûéòè èç öèêëà while è çàâåðøèòü ïðîãó

		// Çàïóñê ìåíþ ÷àòà
		if (chat_menu(accs, rezult.id)) break;		// åñëè âûøëè èç ôóíêöèè ñ false, òî âûéòè èç öèêëà while

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
			if (accs.containsLog(tmp))         //òåñò ïðîâåðêè íà çàíÿòîñòü ëîãèíà
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
			if (tmp.size() > 5) // ïàðîëü äëèíåå 5 ñèìâîëîâ
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
			if (accs.containsName(tmp))         //òåñò ïðîâåðêè íà çàíÿòîñòü name
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

		accs.add_acc(acc); //çàíåñëè ñîçäàííûé àêêàóíò

		//break; // òóò áðýéê íå íóæåí, ìû æå ñîçäàëè àêêàóíò, òåïåðü èäåì ëîãèíèòüñÿ, ò.å. â íåêñò êåéç
	}
	case '2':
	{
		if (accs.count_acc() == 0) // åñëè íåò íè îäíîãî àêêàóíòà, òî ïîïðîñèì ïåðåçàïóñòèòü ÷àò è ñîçäàòü àêêàóíò
		{
			cout << "There is not a single registration! Re-enter the chat and create an account!" << endl;
			return rezult; // çàêðûëè ÷àò, àíàëîã ââîäà q
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
			accs[id].print_recv_massage();
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
				cout << "Enter the username you want to write to: " << endl; // если мы отправляем по имени, то нам нужно предусмотреть то, что они не повторяются
				cin >> receiver;
				if (accs.containsName(receiver))         //occupancy test name
				{
					//add add_sm for this acc and add_rm for reciever
					string msg;
					cout << "Enter you massage: " << endl; // если мы отправляем по имени, то нам нужно предусмотреть то, что они не повторяются
					cin >> msg;

					// узнать айди
					int id_recver = accs.get_id_by_name(receiver);

					// отладка
					//Message tmp1(msg, id, id_recver); // для сендера
					//Message tmp2(msg, id_recver, id); // для реквера
					//
					//accs[id].send_mess.push_back(tmp1);
					//accs[id_recver].recv_mess.push_back(tmp2);

					// сохраняем в принятых у принимающего
					accs[id_recver].set_recv_mess(msg, id);
					
					// сохраняем в отправленных у отправляющего
					accs[id].set_send_mess(msg, id_recver);

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
