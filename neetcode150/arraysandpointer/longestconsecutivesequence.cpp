#include<bits/stdc++.h>
using namespace std; 


// Approach 1 : check if the predessor of every element exists and add 1 in the end for the starting element.
// Mistake in this approach - Checks for indivdual element doesnt account for multiple segments of consecutivity.
// Not a valid approach.
int longestConsecutive_old(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> con;
    for (int x : nums) { 
        con.insert(x);
    }
    int ans = 0;
    for (int x : con) {
        if (con.find(x-1) != con.end()) {
            ans++;
        }
    }

    return ans+1;
}

// Approach 2 : Find out the starting element and then start counting upward ;]. This was the IMP Missing hint.
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> con;
    for (int x : nums) { 
        con.insert(x);
    }
    if (n==0) return 0;
    if (n==1) return 1;
    int max_ans = 0; 
    for (int x : con) {
        if (con.find(x-1) == con.end()) { // No predessor -- potential starting point 
            // starting point found.
            int temp = x;
            int ans = 0;
            while (con.find(x+1) != con.end()) {
                ans++;
                x = x+1;
            }
            max_ans = max(ans, max_ans);
        }
    }

    return max_ans+1; # since we are calculating jumps adding + 1 will give the number of elements which is the desired output
}

int main() {
    vector<int> nums = {1,2,6,7,8};
    int ans = longestConsecutive(nums);
    cout << ans << endl;
}
