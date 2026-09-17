#include <bits/stdc++.h>
using namespace std;

/// @brief Approach 1 : Need to find the largest area : height * (j - i) index to get the whole area. 
/// @brief Brute force approch 
/// @param height 
/// @return 
int maxArea_old(vector<int>& height) {
    int n = height.size();
    int max_area = 0;
    for (int i = 0; i<n; i++) { 
        for (int j = i+1; j<n; j++) { 
            int area = min(height[i], height[j]) * (j - i);
            max_area = max(area, max_area);
        }
    }

    return max_area;
}

/// @brief Approach 2 : Need to optimize using two [pointers approach] 
/// @brief Main condition for increment/decrement the two pointers : between i and j whoever's height is less move that pointer since the chances of encountering a greater event is high.
/// @brief Solved in first attempt
/// @param height 
/// @return 
int maxArea(vector<int>& height) {
    int n = height.size();
    int max_area = 0;
    int i = 0;
    int j = n - 1;
    while (i < j && i < n and j > 0) { 
        int area = min(height[i], height[j]) * (j - i);
        max_area = max(area, max_area);
        if (height[i] == height[j]) { 
            i++; 
            j--;
        }else if (height[i] < height[j]) { 
            i++;
        }
        else {
            j--;
        }
    }

    return max_area;
}

int main()
{
	vector<int> nums = {1,8,6,2,5,4,8,3,7};
	int ans = maxArea(nums);
    cout << ans << endl;
}