
#include "main.hpp"
int main(void)
{
	std::string prompt;
	PhoneBook phone_book;
	while (1)
	{
		std::cout << "enter command" << std::endl;
		std::cin >> prompt;
		if (prompt == "ADD")
			phone_book.add();
		else if (prompt == "SEARCH")
			phone_book.search();
		else if (prompt == "EXIT")
		{
			std::cout << "bye" << std::endl;
			break ;
		}
		else
			std::cout << "this program only accepts ADD, SEARCH and EXIT" << std::endl;
	}
	return (0);
}
