#include <bits/stdc++.h>
using namespace std;

// Need to find the largest rectangle formed in the bar graph
// Width is constant - 1
// Intuition - Use Stack to store area of the bars. PUsh a area and only push another if prev is lesser than it.
// Approach 1 : Using brutal force
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int max_area = 0;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int height = min(heights[i], heights[j]);
            int area = height * (j - i);
            max_area = max(max_area, area);
        }
    }
    return max_area;
}

// Approach 2 : Need to reduce the repetitive iterations.
// for the area of the area we need to track the before and after element of the 
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int max_area = 0;
    for (int i=1;i<n-1;i++) { 
        int before =  heights[i-1];
        int after =  heights[i+1];
        
    }

}


int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = largestRectangleArea(heights);
    cout << "ans : " << ans << endl;
}