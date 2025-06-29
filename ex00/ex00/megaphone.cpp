/*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string s1;
			s1 = argv[i];
			for (int j = 0; j < (int)s1.size(); j++)
			{
				if ('a' <= s1[j] && s1[j] <= 'z')
					s1[j] = std::toupper(s1[j]);
			}
			std::cout << s1;
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
