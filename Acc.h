#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Message
{
public:
	//Message(string mess, int id_send, int id_recv) : _mess(mess), _id_send(id_send), _id_recv(id_recv) {}
	Message(string mess, string name_send, string name_recv) : _mess(mess), _name_send(name_send), _name_recv(name_recv) {}

	string get_mess() { return _mess; }
	//int get_id_send() { return _id_send; }
	//int get_id_recv() { return _id_recv; }
	string get_name_send() { return _name_send; }
	string get_name_recv() { return _name_recv; }

private:
	string _mess;
	//int _id_send;
	//int _id_recv;
	string _name_send;
	string _name_recv;

};

class Account
{
public:
	Account() : _name(""), _login(""), _password(""), my_id(-1) {}

	string get_name() { return _name; }
	string get_login() { return _login; }
	string get_password() { return _password; }

	void set_name(string name) { _name = name; }
	void set_login(string login) { _login = login; }
	void set_password(string password) { _password = password; }
	void set_my_id(int id) { my_id = id; }

	//void set_recv_mess(string mess, int id_sender);
	//void set_send_mess(string mess, int id_recver);

	void set_recv_mess(string mess, string name_sender);
	void set_send_mess(string mess, string name_recver);

	void print_all_send_massage();
	void print_recv_massage();


protected:
	int my_id;
	string _name;
	string _login;
	string _password;

	vector<Message> recv_mess;
	vector<Message> send_mess;

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

	bool containsLog(string login); 
	int get_id_by_login(string login); 
	int get_id_by_name(string name);


	bool containsName(string name);

	Account& operator[](int i) { return data[i]; }

protected:
	int count; // counter of accs
	vector<Account> data;
};

