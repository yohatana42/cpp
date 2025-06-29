#include "main.hpp"

void Contact::set_first_name(std::string f_name)
{
	first_name = f_name;
}

void Contact::set_last_name(std::string l_name)
{
	last_name = l_name;
}

void Contact::set_nickname(std::string n_name)
{
	nickname = n_name;
}

void Contact::set_phone_num(std::string p_num)
{
	phone_number = p_num;
}

void Contact::set_darkest_secret(std::string d_secret)
{
	darkest_secret = d_secret;
}

std::string Contact::get_first_name()
{
	return first_name;
}

std::string Contact::get_last_name()
{
	return last_name;
}

std::string Contact::get_nickname()
{
	return nickname;
}

std::string Contact::get_phone_num()
{
	return phone_number;
}

std::string Contact::get_darkest_secret()
{
	return darkest_secret;
}
