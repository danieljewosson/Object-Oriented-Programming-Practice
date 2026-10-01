#ifndef OOP
#define OOP

#include<cstddef>

int GetSeed();
void SeedRandom(int seed);
int RandomInt(int min, int max);

class MyClass
{
public:

	MyClass(size_t size, size_t size2);
	~MyClass();
	MyClass(const MyClass& other);
	MyClass& operator=(const MyClass& other);
	void print();
	

private:
	int** data;
	size_t size, size2;
};

#endif
