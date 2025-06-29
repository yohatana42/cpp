#include "main.hpp"

void PhoneBook::add()
{
	while (_f_name.empty())
	{
		std::cout << "input first name" << std::endl;
		std::cin >> _f_name;
	}
	std::cout << "input last name" << std::endl;
	std::cin >> _l_name;
	while (_l_name.empty())
	{
		std::cout << "input last name" << std::endl;
		std::cin >> _l_name;
	}
	if (_n_name.empty())
	{
		std::cout << "input nickname" << std::endl;
		std::cin >> _n_name;
	}
	if (_p_num.empty())
	{
		std::cout << "input phone number" << std::endl;
		std::cin >> _p_num;
	}
	if (_d_secret.empty())
	{
		std::cout << "input darkest secret" << std::endl;
		std::cin >> _d_secret;
	}
	this->_contacts[_last_create].set_first_name(_f_name);
	this->_contacts[_last_create].set_last_name(_l_name);
	this->_contacts[_last_create].set_nickname(_n_name);
	this->_contacts[_last_create].set_phone_num(_p_num);
	this->_contacts[_last_create].set_darkest_secret(_d_secret);
	_last_create++;
	if (_last_create == 8)
		_last_create = 0;
}

void PhoneBook::search()
{
	int i = 0;
	while (i < 8)
	{
		_f_name = this->_contacts[i].get_first_name();
		_l_name = this->_contacts[i].get_last_name();
		_n_name = this->_contacts[i].get_nickname();
		if (_f_name.empty())
			return ;
		if (_f_name.length() > 10)
			_f_name = _f_name.substr(0, 9) + ".";
		if (_l_name.length() > 10)
			_l_name = _l_name.substr(0, 9) + ".";
		if (_n_name.length() > 10)
			_n_name = _n_name.substr(0, 9) + ".";
		std::cout << i << "|";
		std::cout << _f_name << "|";
		std::cout << _l_name << "|";
		std::cout << _n_name << std::endl;
		i++;
	}
	std::cout << "chose some index" << std::endl;
	int	index = 0;
	std::cin >> index;
	while (index > 7 && this->_contacts[index].get_first_name().empty())
	{
		std::cout << "retry" << std::endl;
		std::cin >> index;
	}
	std::cout << this->_contacts[index].get_first_name() << std::endl;
	std::cout << this->_contacts[index].get_last_name() << std::endl;
	std::cout << this->_contacts[index].get_nickname() << std::endl;
	std::cout << this->_contacts[index].get_phone_num() << std::endl;
	std::cout << this->_contacts[index].get_darkest_secret() << std::endl;
}

