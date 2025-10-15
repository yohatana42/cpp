#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

 #include <string>
 #include <iostream>
 #include <vector>
 #include <exception>
 #include <algorithm>
 #include <list>

template <typename T>
typename T::iterator easyfind(T& cont, int num)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), num);
	if (it == cont.end())
		throw std::runtime_error("no such number");
	return (it);
}

#endif
