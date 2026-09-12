#include<bits/stdc++.h>
using namespace std; 

//  approach 1 : Brute force : run two for loops and calculate every possible sum of two numbers until target is found
//  Worst case Time complexity - O(n^2)
// Best Case - O(1) if first addition is same as target.
vector<int> twoSum_old(vector<int>& nums, int target) {
    int n = nums.size();

    for(int i=0;i<n;i++)  {
        for (int j=i+1; j<n; j++) {
            if (nums[i] + nums[j] == target) { 
                return {i, j};
            }
        }
    }

    return {};
}

// Approach 2 : Insert the elements into a hashmap containing the index and the element and then iterate over the array and check 
// that target - current_element = exist in the array ? if yes thats the solution 
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> map; 
    // loop for storing every element
    for (int i=0;i<n;i++) { 
        map[nums[i]] = i;
    }

    // loop for checking if the target - current exists in the map; 
    for (int i=0; i<n; i++)  {
        int element_needed = target - nums[i];
        cout << element_needed << " : element needed" << endl;
        cout << i << " : current elemeent" << nums[i] << endl; 

        if (map.find(element_needed) != map.end() && map[element_needed] != i) { 
            // NOTE : The beyond add condition in the above if statement was missed and caused a problem where target - current gave 
            // equal to current elemetn and the map looked up and returned the same elements index.
            // element is foud
            return {i, map[element_needed]};
        }
    }
    return {};
}


int main() { 
    vector<int> que = {3,2,4};
    int target = 6;
    vector<int> ans = twoSum(que, target);
    for (int x : ans) { 
        cout << x << endl; 
    }
}