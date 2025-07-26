#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int n = 10;

	Animal **metas = new Animal*[n];
	std::cout << "=== constructor ===" << std::endl;
	for (int i = 0; i < n;i++)
	{
		if (i < n / 2)
			metas[i] = new Dog();
		else
			metas[i] = new Cat();
	}

	// deep copy の証明をする
	// std::cout << "--- deep copy zone ---" << std::endl;
	// for (int i = 0; i < n;i++)
	// {
	// 	if (i < 2/n)
	// 	{
	// 		Dog *dog = dynamic_cast<Dog*>(metas[i]); // セグフォする
	// 		std::cout << dog->getBrain()->get_ideas()[0] << std::endl;
	// 		delete dog;
	// 	}
	// 	else
	// 	{
	// 		Cat *cat = dynamic_cast<Cat*>(metas[i]);
	// 		std::cout << cat->getBrain()->get_ideas()[0] << std::endl;
	// 		delete cat;
	// 	}
	// }

	std::cout << "=== destructor ===" << std::endl;
	for (int i = 0; i < n;i++)
		delete metas[i];
	delete[] metas;

	return (0);
}
