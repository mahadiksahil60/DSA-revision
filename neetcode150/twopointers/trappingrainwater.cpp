#include <bits/stdc++.h>
using namespace std;

/// @brief Approach 1 : Brute force approach - try all possible combinations for the wall and run another inner loop to reduce the water due to walls in between
/// @param height 
/// @return 
int trap(vector<int>& height) {
    int n = height.size();
    int ans = 0; 
    for(int i=0; i<n; i++) { 
        for (int j = i+1; j < n; j++) {
            
        }
    }    

    return ans;
}

int main()
{
	vector<int> height  = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ans = trap(height);
    cout << ans << endl;
} 