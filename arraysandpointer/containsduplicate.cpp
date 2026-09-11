#include<bits/stdc++.h>
using namespace std; 


// Worst case solution - Run a loop for checking every element - O(n^2)
// Best approach - Use a set to lookup and store elements in O(logn) - overall complexity - O(n*logn)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freq;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        if (freq.contains(nums[i])) { // contains function added in latest c++
            // element not found
            return true;
        }else {
            freq.insert(nums[i]);
        }
    }

    return false;
}


int main() { 
    vector<int> que = {1,2,3,1};
    bool ans = containsDuplicate(que);
    cout << ans << endl;
}