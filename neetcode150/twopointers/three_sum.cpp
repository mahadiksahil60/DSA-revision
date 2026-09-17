#include <bits/stdc++.h>
using namespace std;


// utility function
void print2dVector(vector<vector<int>>& nums) { 
    for (vector<int> x : nums) {
        for (int y : x) { 
            cout << y << " "; 
        }
        cout << endl;
    }
}

/// @brief Approach 1 : apply 2 sum for every element. O(n^2 is accepted). Use two nested loops and find the third element from the set.
/// @brief Time complexity - O(n^2)  Space complexity - O(n^2) - since we are using map to store all the n elements
/// @param nums 
/// @return 
vector<vector<int>> threeSum_old(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> indexMap; 
    for (int i=0;i<n;i++) {
        indexMap[nums[i]] = i;
    }
    set<vector<int>> ans;
    for (int i=0; i<n; i++) {
        for (int j = i+1; j<n; j++) { // j = i+1 because we dont want to process the same element twice.
            int element_needed = -(nums[i] + nums[j]);
            if (indexMap.find(element_needed) != indexMap.end() && indexMap[element_needed] != i && indexMap[element_needed] != j) { 
                // third element found, 
                vector<int> triplet = {nums[i], nums[j], element_needed};
                sort(triplet.begin(), triplet.end());
                ans.insert(triplet);
            }
        }
    }

    vector<vector<int>> finalans(
        ans.begin(), ans.end()
    );

    return finalans;
}

/// @brief Approach 2 : Solve without using extra map. Sort the array before hand.
/// @brief fix the first element and use two pointers for the remaining array. Implement two-sum-two problem over again
/// @brief Need to avoid duplicate without using set. Since the array is sorted duplicate values will stick to one another so we need to skip duplicates from the loop
/// @param nums 
/// @return 
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans; 
    for (int i=0; i<n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int l = i+1; 
        int r = n-1;

        while(l < r && l < n && r > i) { 

            if (nums[r]+nums[l] == -(nums[i])) { 
                 ans.push_back({nums[r], nums[l], nums[i]});
                 r--; l++; // missed it need to increment both the pointers in case of a valid match otherwise it will get stuck in a infinite loop.

                 // IMP STEP : duplicate found now we need to move to the next non same number.
                 while (l < r && nums[l]==nums[l-1]) {
                    l++;
                 }
                 while(r > l && nums[r] == nums[r+1]) {
                    r--;
                 }
            }else if (nums[r]+nums[l] < -(nums[i])) { 
                l++;
            } else {
                r--;
            }
        }
    }

    return ans;
}


int main()
{
	vector<int> nums = {1,2,0,1,0,0,0,0};
	vector<vector<int>> ans = threeSum(nums);
    print2dVector(ans);
}