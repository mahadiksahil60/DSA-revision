#include <bits/stdc++.h>
using namespace std;

void print2dArray(vector<vector<int>> &nums)
{
	for (vector<int> x : nums)
	{
		for (int y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
}

/// @brief Accepted time complexity - O(n^2)
/// @brief apply two sum for each element
/// @brief
/// @param nums vector<int>
/// @return vector<vector<int>>
vector<vector<int>> threeSum(vector<int> &nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
	}
}

int main()
{
	vector<int> nums = {2, 7, 11, 15};
	vector<int> ans = threeSum(nums);
	print2dArray(ans);
}