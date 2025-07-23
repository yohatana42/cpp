#ifndef BRAIN_HPP
 #define BRAIN_HPP

 #include <string>
 #include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
		~Brain();
		std::string _ideas[100];
};

#endif
