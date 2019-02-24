#include <iostream> 

void printArr(int arr[], int index) {
	for (int i = 0; i < index; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void findCombinationsUtil(int arr[], int index, int num, int reducedNum)
{
	if (reducedNum < 0)
		return;

	if (reducedNum == 0)
	{
		printArr(arr, index);
		return;
	}

	int prev = (index == 0) ? 1 : arr[index - 1];

	for (int k = prev; k <= num; k++)
	{
		arr[index] = k;

		findCombinationsUtil(arr, index + 1, num, reducedNum - k);
	}
}

void findCombinations(int n)
{
	findCombinationsUtil(new int[n], 0, n, n);
}

int main()
{
	int n;

	std::cin >> n;

	findCombinations(n);
	return 0;
}