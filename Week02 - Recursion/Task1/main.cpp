#include <iostream>
#include <vector>
#include "C:\Users\Kristiyan Gergov\Desktop\Projects\Ubisoft\Week02 - Recursion\Combinations\CombinationsFinder.h"

int main()
{
	int n;

	std::cin >> n;

	CombinationsFinder com = CombinationsFinder();
	com.printCombinations(com.findAll(n));

	system("pause");
	return 0;
}