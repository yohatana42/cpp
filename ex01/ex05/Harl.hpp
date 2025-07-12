#ifndef HARL_H
 #define HARL_H

 #include <string>
 #include <iostream>

class Harl
{
    public:
        Harl();
        void complain(std::string level);
    private:
        typedef void (Harl::*funcPtr)();
        funcPtr _func[4];
        void debug();
        void info();
        void warning();
        void error();
};

#endif