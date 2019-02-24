#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class CombinationsFinder
{
	
private:
	void findNumbers(std::vector<int>& ar, int sum, std::vector<std::vector<int>>&res, std::vector<int>& r, int i)
	{
		if (sum < 0)
			return;

		if (sum == 0)
		{
			res.push_back(r);
			return;
		}

		while (i < ar.size() && sum - ar[i] >= 0)
		{
			r.push_back(ar[i]);

			findNumbers(ar, sum - ar[i], res, r, i);
			i++;

			r.pop_back();
		}
	}

public:

	void printCombinations(std::vector<std::vector<int>> res) {
		if (res.size() == 0)
		{
			std::cout << "No available combinations!";
			return;
		}

		for (int i = 0; i < res.size(); i++)
		{
			if (res[i].size() > 0)
			{
				for (int j = 0; j < res[i].size(); j++) {
					if (j == res[i].size() - 1)
						std::cout << res[i][j] << std::endl;
					else
						std::cout << res[i][j] << " + ";
				}
			}
		}
	}


	std::vector<std::vector<int>> findAll(std::vector<int>& ar, int sum)
	{
		sort(ar.begin(), ar.end());

		ar.erase(unique(ar.begin(), ar.end()), ar.end());

		std::vector<int> r;
		std::vector<std::vector<int>> res;
		findNumbers(ar, sum, res, r, 0);

		return res;
	}

	std::vector<std::vector<int>> findAll(int sum) {

		std::vector<int> arr;

		for (int i = 1; i < sum; i++)
			arr.push_back(i);

		return findAll(arr, sum);
	}
};