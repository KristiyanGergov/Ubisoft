// К Р И С Т И Я Н   Г Е Р Г О В

#include <vector>
#include <iostream>
#include "C:\Users\Kristiyan Gergov\Desktop\Projects\Ubisoft\Week02 - Recursion\Task1\CombinationsFinder.h"

int main()
{

	int n, k;

	std::cout << "Enter N: ";
	std::cin >> n;

	std::cout << "Enter K: ";
	std::cin >> k;

	std::vector<int> arr;
	
	std::cout << "Enter " << k << " numbers: ";

	for (int i = 0; i < k; i++)
	{
		int curr;
		std::cin >> curr;
		arr.push_back(curr);
	}

	CombinationsFinder com = CombinationsFinder();
	com.printCombinations(com.findAll(arr, n));

	system("pause");
}