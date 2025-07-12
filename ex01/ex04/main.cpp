#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid argument" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string before = argv[2];
	std::string after = argv[3];
	std::ifstream infile(filename);
	std::ofstream outfile(filename + ".replace");
	Replace replace;

	if (!infile)
		return (return_err("file open fail"));
	if (!outfile)
		return (return_err("file open fail"));

	std::string line;
	std::string after_line;
	while (std::getline(infile, line))
	{
		std::cout << line << std::endl;
		after_line = replace.exec_replace(line, before, after);
		outfile << after_line;
		if (!infile.eof())
			outfile << std::endl;
	}
	return (0);
}

int	return_err(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}