#include <bits/stdc++.h>
using namespace std;

/// @brief Approach 1 : Brute force approach - use pointer i and j, stoart from first non zero element nad then increment j to find boundays and then calculate the water betwen them and then move onto next container 
/// @brief This approach was wrong. 
/// @param height
/// @return
int trap_old(vector<int> &height)
{
    int n = height.size();
    int ans = 0;
    int i = 0;
    int j = i+1;

    while (j < n)
    {
        while (i < j && height[i] == 0) {
            i++;
        }
        cout << "this first position of the i should be 1" << i << endl;
        while (height[j] == 0 and j - i <= 1) { // need rework
            j++;
        }
        cout << "The first index of j should be 3" << j << endl;
        // calculate water between these two indexes
        int temp = min(height[i], height[j]) * (j - i - 1);
        int between = 0; 
        for (int k=i+1; k<j; k++) {
            between += height[k];
        }
        cout << "between" << between << endl;
        int final_temp = abs(temp - between);
        cout << "checking final temp for first iteration" << final_temp << endl;
        ans += final_temp;

        i = j; // need rework 
        j++;
    }
    return ans;
}

int trap(vector<int> &height) {
    int n = height.size();
    int ans = 0;
    int i = 0;
    int j = n-1;
    int left_max = 0;
    int right_max = 0 ;;
    while (i < j) { 
        if (height[i] <= height[j]) {
            if(height[i] >= left_max) {
                left_max = height[i];
            }
            else {
                ans += left_max - height[i];
            }

            i++;
        }
        else { 
            if (height[j] >= right_max) { 
                right_max = height[j];
            }
            else { 
                ans += right_max - height[j];
            }

            j--;
        }
    }
    return ans;
}


int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(height);
    cout << ans << endl;
}