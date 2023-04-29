#include "Acc.h"
account::account(string name, string login, string password) : _name(name), _login(login), _password(password)
{

}
account::account(string name, string login, string password) : _login(login), _password(password)
{

}