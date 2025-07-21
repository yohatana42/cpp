#ifndef REPLACE_H
 #define REPLACE_H

# include <string>
# include <iostream>
# include <fstream>

class Replace
{
    public:
        Replace();
        std::string exec_replace(std::string line,
                            std::string before,
                            std::string after);
    private:
};

int	return_err(std::string str);

#endif
