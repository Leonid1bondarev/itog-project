#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Message
{
public:
	Message(string mess, int id_send, int id_recv) : _mess(mess), _id_send(id_send), _id_recv(id_recv) {}

	string get_mess() { return _mess; }
	int get_id_send() { return _id_send; }

private:
	string _mess;
	int _id_send;
	int _id_recv;
};

class Account
{
public:
	Account() : _name(""), _login(""), _password(""), my_id(-1) {}
	//Account(string name, string login, string password);
	//Account(string login, string password);

	string get_name() { return _name; }
	string get_login() { return _login; }
	string get_password() { return _password; }

	void set_name(string name) { _name = name; }
	void set_login(string login) { _login = login; }
	void set_password(string password) { _password = password; }
	void set_my_id(int id) { my_id = id; }

	//string srm(); //func show received messages
	//string ssm();

	//void add_rm(string message)
	//{
	//	crm++;
	//	received_message.push_back(message);
	//}
	//void add_sm(string message)
	//{
	//	csm++;
	//	sent_message.push_back(message);
	//}

	void set_recv_mess(string mess, int id_sender);
	void set_send_mess(string mess, int id_recver);
	//string get_recv_mess();

	//void print_all_send_massage();
	void print_recv_massage();


protected:
	int my_id;
	string _name;
	string _login;
	string _password;

	vector<Message> recv_mess;
	vector<Message> send_mess;

	//vector<string> received_message;
	//int crm = 0; //counter received messages
	//vector<string> sent_message;
	//int csm = 0; //counter sent messages
};

class Accounts_data
{
public:
	Accounts_data()
	{
		count = 0;
	}

	inline int count_acc() { return count; }

	void add_acc(Account new_acc)
	{
		count++;
		data.push_back(new_acc);
	}

	bool containsLog(string login); // ïðîâåðêà, çàðåãàí òàêîé àêêàóíò èëè íåò
	int get_id_by_login(string login); // id ýòîãî ëîãèíà (íîìåð)
	int get_id_by_name(string name);

	bool containsName(string name);

	Account& operator[](int i) { return data[i]; }

protected:
	int count; // êîëè÷åñòâî èìèåþùèõñÿ àêêàóíòîâ
	vector<Account> data;
};
