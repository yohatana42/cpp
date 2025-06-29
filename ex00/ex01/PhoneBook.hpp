#ifndef PHONEBOOK_H
 #define PHONEBOOK_H

# include "main.hpp"

class PhoneBook
{
	public:
		void add();
		void search();
	private:
		Contact _contacts[8];
		int		_last_create;
		std::string _f_name;
		std::string _l_name;
		std::string _n_name;
		std::string _p_num;
		std::string _d_secret;
};

#endif
