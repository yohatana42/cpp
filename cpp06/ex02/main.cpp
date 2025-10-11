#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "castBase.hpp"

int main()
{
	castBase castbase;
	Base *base = castbase.generate();
	castbase.identify(base);
	return (0);
}
