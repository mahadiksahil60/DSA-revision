#include<bits/stdc++.h>
using namespace std; 


void printIntArray(vector<int>& nums) {
    cout << "[";
    for (int x : nums) { 
        cout << x << ", "; 
    }
    cout << "]";
    cout << endl;
}

// Catch : 
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Approach 1 : Calculate prefix in one pass and calcuate suffix in another and then just add 
// Solved without hint
// Time Complexity = O(n)   Space complexity - O(n) -- need to optimize space complexity
vector<int> productExceptSelf_old(vector<int>& nums) {
    int n = nums.size();
    cout << "size : " << n << endl;

    vector<int> prefix(nums.size(), 0);
    vector<int> suffix(nums.size(), 0);

    int pre = 1; // IMP : Initializatuon of variable which stores multiple should never be zero but 1  
    for (int i=0; i<n; i++) { 
        pre *= nums[i];
        prefix[i] = pre;
    }

    // reverse logic for suffix
    int suff = 1;
    for (int i=n-1; i>=0; i--) { 
        suff *= nums[i];
        suffix[i] = suff;
    }

    // cout << "prefix : ";
    // printIntArray(prefix);
    // cout << "suffix : ";
    // printIntArray(suffix);
    
    vector<int> ans; 

    // Prefix and suffix arrays are perfectly constructed now just multiply prefix and suffix 
    // for first element there is no prefix
    ans.push_back(suffix[1]);
    for (int i=1;i<n-1;i++) { 
        int ele = prefix[i-1] * suffix[i+1];
        ans.push_back(ele);
    }
    // for the last element there is no suffix 
    ans.push_back(prefix[suffix.size()-2]);

    return ans;
    
}

// Approach 2 : Optimized space complexity, use the same ans array to apply the prefix and suffix multiplication.
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(nums.size(), 1); 
    int pre = 1;
    for (int i=0; i<n; i++) { 
        ans[i] *= pre; // this handles the prefix of the first element
        pre *= nums[i];
    }

    // reverse logic for suffix
    int suff = 1;
    for (int i=n-1; i>=0; i--) { 
        ans[i] *= suff; // this handles the suffix of the first element
        suff *= nums[i];
    }    

    return ans;
}



int main() { 
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    printIntArray(ans);
}