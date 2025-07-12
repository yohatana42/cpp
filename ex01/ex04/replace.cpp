# include "replace.hpp"

Replace::Replace() {}

std::string Replace::exec_replace(std::string line, 
                    std::string before, 
                    std::string after)
{
    int i = 0;
    while (line[i])
    {
        std::cout << i << std::endl;
        std::cout << line[i] << std::endl;
        int find_spot = line.find(before);
        if (find_spot < 0)
            return (line);
        if (find_spot < i)
            continue ;
        line.erase(find_spot, before.size());
        line.insert(find_spot, after);
    }
    return (line);
}