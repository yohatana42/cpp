#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int n = 10;

	Animal **metas = new Animal*[n];
	std::cout << "=== constructor ===" << std::endl;
	for (int i = 0; i < n;i++)
	{
		std::cout << "createing #";
		std::cout << i << std::endl;
		if (i < n / 2)
			metas[i] = new Dog();
		else
			metas[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "=== destructor ===" << std::endl;
	for (int i = 0; i < n;i++)
		delete metas[i];
	delete[] metas;

	return (0);
}
