#include "castBase.hpp"

castBase::castBase() {}

castBase::castBase(const castBase& src)
{
	(void)src;
}
castBase& castBase::operator=(const castBase& src)
{
	(void)src;
	return (*this);
}

castBase::~castBase() {}

Base* castBase::generate(void)
{
	srand(time(0));
	int num = rand() % 2;
	if (num % 3 == 1)
	{
		return (new A());
	}
	else if (num % 3 == 2)
	{
		return (new B());
	}
	return (new C());
}

void castBase::identify(Base* p)
{
		if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
}
}

void castBase::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "C" << std::endl;
		}
	}
}
