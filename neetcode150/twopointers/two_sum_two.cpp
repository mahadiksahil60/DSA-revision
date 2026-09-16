#include <bits/stdc++.h>
using namespace std;

// Catch - Your solution must use only constant extra space
// which means no hashmap and no duplicate vectors

// Hint : Sorted in ascending order

// Approach 1 : start with two pointers from index 0 and 1 and if target is greater than the sum
// increment i otherwise increment  j
// This approach is not valid
vector<int> twoSum_old(vector<int> &numbers, int target)
{
	int n = numbers.size();
	int i = 0;
	int j = i + 1;
	while (i < n && j < n)
	{
		if (numbers[i] + numbers[j] == target)
		{
			return {i + 1, j + 1};
		}
		else if (numbers[i] + numbers[j] > target)
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return {};
}

/// @brief This approach is incorrect because we are moving in opp direction and discarding the movment of j pointer
/// @param numbers
/// @param target
/// @return
vector<int> twoSum_old_v2(vector<int> &numbers, int target)
{
	int n = numbers.size();
	int i = n / 2;
	int j = i + 1;
	while (i > 0 && j < n)
	{
		cout << "starting indices " << i << " " << j << endl;

		if (numbers[i] + numbers[j] == target)
		{
			cout << "inspecting indices in if " << i << " " << j << endl;
			return {i + 1, j + 1};
		}

		else if (numbers[i] + numbers[j] > target)
		{
			while (i > 0 && numbers[i] + numbers[j] > target)
			{
				i--;
			}

			cout << "inspecting indices in else if " << i << " " << j << endl;
			if (numbers[i] + numbers[j] == target)
				return {i + 1, j + 1};
		}
		else
		{
			while (j < n && numbers[i] + numbers[j] < target)
			{
				j++;
			}
			cout << "inspecting indices in else " << i << " " << j << endl;
			if (numbers[i] + numbers[j] == target)
				return {i + 1, j + 1};
		}
	}
	return {};
}

/// @brief In this approach will keep the pointers in opp direction. This was the first intuition.
/// @param numbers
/// @param target
/// @return
vector<int> twoSum(vector<int> &numbers, int target)
{
	int n = numbers.size();
	int i = 0;
	int j = n - 1;
	while (i < j && i < n && j > 0)
	{
		if (numbers[i] + numbers[j] == target)
		{
			return {i + 1, j + 1};
		}
		else if (numbers[i] + numbers[j] > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	return {};
}

int main()
{
	vector<int> que = {2, 7, 11, 15};
	int target = 9;
	vector<int> ans = twoSum(que, target);
	for (int x : ans)
	{
		cout << x << endl;
	}
}