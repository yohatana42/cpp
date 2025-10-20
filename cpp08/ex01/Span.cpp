#include "Span.hpp"

Span::Span(unsigned int n)
{
	// resizeだと0埋めされる？
	_vec.reserve(n);
	_contents_count = 0;
	_contents_max = n;
}

Span::Span(const Span& src)
{
	_vec.reserve(src._vec.size());
	_vec = src._vec;
	_contents_count = src._contents_count;
	_contents_max = src._contents_max;
}

Span& Span::operator=(const Span& src)
{
	_vec.reserve(src._vec.size());
	_vec = src._vec;
	_contents_count = src._contents_count;
	_contents_max = src._contents_max;
	return (*this);
}

Span::~Span() {}

int Span::shortestSpan()
{
	if (_contents_count < 2)
		throw (std::runtime_error("Not enough numbers stored"));
	std::sort(_vec.begin(), _vec.end());

	int diff;
	int temp;
	for (int i = 0; i < _contents_count -1; i++)
	{
		temp = _vec[i + 1] - _vec[i];
		if (i == 0)
			diff = temp;
		else
		{
			if (temp < diff)
				diff = temp;
		}
	}
	return (diff);
}

int Span::longestSpan()
{
	if (_contents_count < 2)
		throw (std::runtime_error("Not enough numbers stored"));
	std::sort(_vec.begin(), _vec.end());
	return (_vec[_contents_count - 1] - _vec[0]);
}

void Span::addNumber(int num)
{
	if (_contents_count + 1 > _contents_max)
	{
		throw (std::runtime_error("Item limit reached"));
	}
	_contents_count++;
	_vec.push_back(num);

}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		_vec.push_back(*begin);
		begin++;
		_contents_count++;
	}
}
