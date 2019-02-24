#include <iostream>
#include <vector>
#include "C:\Users\Kristiyan Gergov\Desktop\Projects\Ubisoft\Week02 - Recursion\Combinations\CombinationsFinder.h"

int main()
{
	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	int n = arr.size();

	int sum = 4;

	CombinationsFinder com = CombinationsFinder();
	com.printCombinations(com.findAll(arr, sum));

	system("pause");
}