#include<bits/stdc++.h>
using namespace std; 

void printIntArray(vector<int>& nums) { 
    for (int x : nums) { 
        cout << x <<  " "; 
    } 
    cout << endl;
}

void printIntSet(set<int, greater<int>>& nums) { 
    for (int x : nums) { 
        cout << x << " ";
    }
    cout << endl;
}

// Problem : find top k frequent elements - 
// first approach - make a freq map with elemetns and count and the iterate over it to find top k frequent elements  
// Solution passed - No hints 
// Time complexity - O(n^2)
vector<int> topKFrequent_old(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map; 
    for (int x : nums) { // O(n)
        map[x]++;
    }

    set<int, greater<int>> temp; // this is how set is declared if sorting is needed.
    vector<int> ans; 
    for (const auto& [key, val] : map) { // O(m)
        temp.insert(val); // O(logm)
    }

    for (int num : temp) {    // This causes the time complexity to jump to n^2 in case all elements occur with diff freq
        for (const auto& [key,value] : map) { 
            if (value == num) { 
                ans.push_back(key);
            }
        }
    }

    return vector<int>(ans.begin(), ans.begin() + k);
}   // Overall time complexity - O(n) + O(m)*O(logm) + O(m^m)


// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// Approach 2 : The initial idea was to create a ele -> freq map and sort account to the values of the map 
            //  But we cannot sort a map according to values - 
            // New technique 
            // - create two maps first one num => freq
            // - Create a second map freq => array of nums
            // We already knew the max freq can be n -> max length of the array 
            // Ran a reverse loop lookup the freq using rev_map and inserted into the ans variable till desired elements are received
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mapp;  // from num -> freq 
    for (int x : nums) { // O(n) 
        mapp[x]++;
    }

    unordered_map<int, vector<int>> rev_map; 
    for (const auto& [key, value] : mapp) { 
        rev_map[value].push_back(key);
    }

    vector<int> ans; 

    int counter = 0; 
    for (int i = nums.size(); i > 0; i--) {
        if (rev_map.find(i) != rev_map.end()) 
        {
            // element found
            for (int x : rev_map[i])  { 
                if (ans.size() > k-1) return ans;
                ans.push_back(x); 
            }
            
        }
    }

    return ans;
}

int main() { 
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int x : ans) { 
        cout << x << endl;
    }
}