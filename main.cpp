#include <iostream>

#include "Acc.h"

//using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//����� ��������
	Accounts_data accs; // ��� ����� ��������� ��� ������ � �� ������
	/*cout << "Count accs: " << accs.count_acc() << endl; //����� ���������� ��������� �������

	Account first_acc("Evgen", "strelok", "QWE123rt"); // �������� ������ ���
	Account second_acc("Leonid", "voin", "asdf453");	// �������� ������ ���

	cout << first_acc.get_login() << endl;				//����� ������ �� ������� ��������

	accs.add_acc(first_acc);		//�������� ������ ��� � ����
	accs.add_acc(second_acc);		//�������� ������ ��� � ����

	cout << "Count accs: " << accs.count_acc() << endl;	//����� ���������� ��������� �������

	if (accs.contains("voin")) cout << "Login is busy\n";		//���� �������� �� ��������� ������
	else cout << "Login is free\n";

	if (accs.contains("strelok")) cout << "Login is busy\n";	//���� �������� �� ��������� ������
	else cout << "Login is free\n";

	if (accs.contains("voin123")) cout << "Login is busy\n";	//���� �������� �� ��������� ������
	else cout << "Login is free\n";

	//����� ������ ����
	//TO DO
	*/
	string login, password, name; //������ ��������(�������� �� ���� ��� ����, ����� ������ �� � ����� ����� ����)


	cout << "����� ���������� � �������� ������ ������� ������, ���������� ���!" << endl;
	while (true)
	{
		cout << "�������� ���� �� ���������" << endl
			<< "1 - ������������������" << endl
			<< "2 - ����� � �������" << endl
			<< "q - ����� ����� �� ���������" << endl;
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
				cout << "������� ����� ��� ������ ��������: " << endl;
				cin >> login;
				if (accs.containsLog(login))         //���� �������� �� ��������� ������
				{
					cout << "Login is busy\n";
				}
				else
				{
					cout << "Login is free\n";
					break;
				}
			}
				cout << "������� ������ ��� ������ ��������: " << endl;
				cin >> password;
				while (true)
				{
					cout << "���������� ��� ��� ������ ��������" << endl;  
					cin >> name;
					if (accs.containsName(name))         //���� �������� �� ��������� name
					{
						cout << "Name is busy\n";
					}
					else
					{
						cout << "Name is free\n";
						break;
					}
				}
				//Account first_acc(name, login, password);       //���� ����������� �������� ��� �����
				//accs.add_acc(first_acc); //������� ��������� �������
			break;
		case '2':
			while (true)
			{
				cout << "������� ����� ��� ������ ��������: " << endl;
				cin >> login;
				if (accs.containsLog(login))      /*����, ����������� ������� ������ � ����, ���� ������� � ���� ��������� ��� ���,
					�� ���� ��������� ��� ���� ���� �������*/
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
				cout << "������� ������ ��� ������ ��������: " << endl;
				cin >> password;
				if (accs.containsPassword(password))         //���� �������� �� ��������� ������
				{
					break;
				}
				else
				{
					cout << "Wrong password\n";
				}
			}
			//name = _name; // ������������ ��� ��������, ������� ����� ������������ � ��������� � ����� �������(��� ������� ����,
			//������� ���������� ��� ��������, � ������� �� �����)
			break;
		default:
			cout << "����������� ������ ��������" << endl;
			break;
		}
		cout << "�� ����� � ������� " << name << endl;


		Account first_acc(name, login, password);     /*������� ����� ��� ���������� ��������(������ ��� ������ ���� ����� ������� �����,
		�� ���� �������� ��� ���� �����, �� ����� ������, �� �������� � ���, ������ �������� ���-�� �����������*/


		accs.add_acc(first_acc); //������� ��������� �������

		while (true)
		{
			cout << "�������� ���� �� ������������� ��������: " << endl
				<< "1 - ���������� ���������� ���������" << endl
				<< "2 - ���������� ������������ ���������" << endl
				<< "3 - �������� ����� ������" << endl
				<< "q - ����� ����� �� ��������" << endl;
			char choice2;
			cin >> choice2;
			if (choice2 == 'q')
			{
				cout << "�� ����� �� �������� " << name << endl;
				break;
			}
			switch (choice2)
			{
			case '1':
				cout << "�� �������� ��������� ���������: " << endl;

				break;
			case '2':
				cout << "�� ��������� ��������� ���������: " << endl;
				break;
			case '3':
				string receiver;
				while (true)
				{
					cout << "������� ��� ������������, �������� �� ������ ��������: " << endl;
					cin >> receiver;
					if (accs.containsName(receiver))         //���� �������� �� ��������� name
					{
						//�������� ���������� ������� �������� ���������
						break;
					}
					else
					{
						cout << "������������ � ����� ������ �� ������\n";
					}
				}
				break;
			default:
				cout << "����������� ������ ��������" << endl;
				break;
			}
		}
		
	}

	return 0;
}