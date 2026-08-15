#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::converter(argv[1]);
		return 0;
	}

	if (argc > 2)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << "=== Test " << i << ": " << argv[i] << " ===" << std::endl;
			ScalarConverter::converter(argv[i]);
			if (i + 1 < argc)
				std::cout << std::endl;
		}
		return 0;
	}

	

	for (int i = 0; i < argc ; ++i)
	{
		std::cout << "=== Test " << (i + 1) << ": " << argv[i] << " ===" << std::endl;
		ScalarConverter::converter(argv[i]);
		if (i + 1 < argc)
			std::cout << std::endl;
	}

	return 0;
}
