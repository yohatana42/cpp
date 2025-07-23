#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	// wrong sounds
	std::cout << "=== wrong ===" << std::endl;
	const WrongAnimal* metakamo = new WrongAnimal();
	const WrongAnimal* nekokamo = new WrongCat();
	std::cout << nekokamo->getType() << " " << std::endl;
	nekokamo->makeSound(); //will output the cat sound!
	metakamo->makeSound();
	delete metakamo;
	delete nekokamo;

	return (0);
}
