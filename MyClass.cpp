#include <iostream>
#include "MyClass.h"

int GetSeed()
{
    return static_cast<int>(std::time(nullptr));
}

void SeedRandom(int seed)
{
    std::srand(seed);
}

int RandomInt(int min, int max)
{
    return std::rand() % (max - min + 1) + min;
}


MyClass::MyClass(size_t size, size_t size2) : size(size),size2(size2),data(new int* [size])
{
    for (size_t i = 0; i < size; ++i)
    {
        this->data[i] = new int[size2];

        for (size_t j = 0; j < size2; ++j)
        {
            this->data[i][j] = RandomInt(1, 100);
        }
    }
}

MyClass::~MyClass()
{
    for (size_t i = 0; i < size; ++i)
    {
        delete[] this->data[i];
    }

    delete[] this->data;
}

MyClass::MyClass(const MyClass& other) : size(other.size),size2(other.size2),data(new int* [other.size])
{
    for (size_t i = 0; i < other.size; ++i)
    {
        this->data[i] = new int[other.size2];

        for (size_t j = 0; j < other.size2; ++j)
        {
            this->data[i][j] = other.data[i][j];
        }
    }
}

MyClass& MyClass::operator=(const MyClass& other)
{
    if (this == &other)
        return *this;

    if (this->data != nullptr)
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete[] this->data[i];
        }
        delete[] this->data;
    }

    this->size = other.size;
    this->size2 = other.size2;
    this->data = new int* [other.size];

    for (size_t i = 0; i < other.size; ++i)
    {
        this->data[i] = new int[other.size2];

        for (size_t j = 0; j < other.size2; ++j)
        {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

void MyClass::print()
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size2; ++j)
        {
            std::cout << data[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}
