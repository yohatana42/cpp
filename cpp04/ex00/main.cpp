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
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// wrong sounds
	const WrongAnimal* metakamo = new WrongAnimal();
	const WrongAnimal* nekokamo = new WrongCat();
	std::cout << nekokamo->getType() << " " << std::endl;
	nekokamo->makeSound(); //will output the cat sound!
	metakamo->makeSound();
	return (0);
}
