#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "hi! this is brain" << std::endl;
	_ideas[0] = "aaaa";
}

Brain::Brain(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "bye! this is brain" << std::endl;
}
