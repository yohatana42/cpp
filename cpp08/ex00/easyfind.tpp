
template <class T>
T add(T a, T b)
{
	return a + b; // a + bの結果を返す
}

template <class T>
int easyfind(T cont, int num)
{
	int i = 0;

	T::iterator it = cont.begin();
	while (it != cont.end())
	{
		if (it->first == num)
			return (i);
		i++;
		it++;
	}
	throw std::exception("no such number");
}
