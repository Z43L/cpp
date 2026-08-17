#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "=== EMPTY ARRAY ===" << std::endl;

	Array<int> empty;

	std::cout << "size: " << empty.size() << std::endl;

	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught" << std::endl;
	}


	std::cout << "\n=== INT ARRAY ===" << std::endl;

	Array<int> numbers(5);

	std::cout << "size: " << numbers.size() << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << std::endl;


	std::cout << "\n=== MODIFY ARRAY ===" << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << std::endl;


	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;

	Array<int> copy(numbers);

	copy[0] = 999;

	std::cout << "original[0]: " << numbers[0] << std::endl;
	std::cout << "copy[0]:     " << copy[0] << std::endl;


	std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;

	Array<int> assigned(2);

	assigned = numbers;

	assigned[1] = 777;

	std::cout << "original[1]: " << numbers[1] << std::endl;
	std::cout << "assigned[1]: " << assigned[1] << std::endl;


	std::cout << "\n=== OUT OF BOUNDS ===" << std::endl;

	try
	{
		std::cout << numbers[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught" << std::endl;
	}


	std::cout << "\n=== STRING ARRAY ===" << std::endl;

	Array<std::string> strings(3);

	strings[0] = "Hello";
	strings[1] = "42";
	strings[2] = "World";

	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << std::endl;


	return 0;
}
