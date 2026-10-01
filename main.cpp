#include <iostream>
#include <ctime>
#include <cstdlib>
#include "MyClass.h"

int main()
{
	SeedRandom(GetSeed());

	MyClass a (5, 7);
	MyClass b(a);

	a.print();
	std::cout << std::endl;
	b.print();

	MyClass c(5, 4);
	MyClass d(2, 3);
	MyClass e(1, 2);

	std::cout << "\n\n\n";

	e = d = c;
	e.print();

	std::cout << "\n\n\n";

	d = d;
	d.print();

}
	