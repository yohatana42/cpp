#ifndef ITER_HPP
 #define ITER_HPP

 #include <string>
 #include <iostream>

template<typename T>
void iter(T *a,const int length, void (*p_func)(const T a))
{
	for (int i = 0; i < length; i++)
	{
		p_func(a[i]);
	}
}

template<typename T>
void func(T a)
{
	std::cout << a << std::endl;
}


#endif
