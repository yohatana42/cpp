#ifndef ARRAY_HPP
 #define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template<typename T>
class Array
{
	public :
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int num)
		{
			_array = new T[num]();
			_size = num;
		}

		Array(const Array& src)
		{
			_size = src._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = src._array[i];
			}
		}

		Array& operator=(const Array& src)
		{
			if (*this == src)
				return (*this);
			delete[] _array;
			_size = src._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = src._array[i];
			}
			return (*this);
		}

		~Array()
		{
			delete[] _array;
		}
		unsigned int size() const
		{
			return (_size);
		}

		T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return (_array[index]);
		}

	private :
		T *_array;
		unsigned int _size;

};

#endif
