#include <iostream>
#include <vector>
#include "CombinationsFinder.h"

int main()
{
	int n;

	std::cout << "Enter N: ";
	std::cin >> n;

	CombinationsFinder com = CombinationsFinder();
	com.printCombinations(com.findAll(n));

	system("pause");
	return 0;
}