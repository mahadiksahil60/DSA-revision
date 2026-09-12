#include<bits/stdc++.h>
using namespace std; 

void print2dVectorString(const vector<vector<string>>& vec) {
    for (const auto& row : vec) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

std::string printIntArray(const std::vector<int>& vec) {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i < vec.size() - 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

// In an array of strings we have to group together anagrams 
// Approach 1 : Brute Force : Sort all the elements in copy array and store them as index and then reconstruct the entire array space with original strs array - Solved wihtout hint 
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    if (n == 1) return {{strs[0]}};
    vector<string> strs2 = strs;
    unordered_map<string, vector<int>> map;
    for (int i=0; i<n; i++) { 
           sort(strs2[i].begin(), strs2[i].end()); // after sorting the anagrams will become similar will store all the indices in a map 
           map[strs2[i]].push_back(i);
    }

    // cout << printIntArray(map[strs[0]]) << endl;
    // Creating the final ans by pushing anagrams togetther in an array and pushing temp into final array
    vector<vector<string>> ans; 
    for (const auto& [key, vec] : map)  {
        vector<string> temp;
        for (int i=0; i<vec.size(); i++) { 
            temp.push_back(strs[vec[i]]);
        }
        ans.push_back(temp);
    } 
    return ans;
}

int main() { 
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    int target = 6;
    vector<vector<string>> ans = groupAnagrams(strs);
    print2dVectorString(ans); 
}