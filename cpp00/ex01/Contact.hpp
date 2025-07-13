
#ifndef CONTACT_H
 #define CONTACT_H

# include "main.hpp"

class Contact
{
	public:
		void set_first_name(std::string f_name);
		std::string get_first_name();
		void set_last_name(std::string l_name);
		std::string get_last_name();
		void set_nickname(std::string n_name);
		std::string get_nickname();
		void set_phone_num(std::string p_num);
		std::string get_phone_num();
		void set_darkest_secret(std::string d_secret);
		std::string get_darkest_secret();

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
