#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Brute force approach. Time complexity - O(n^2) Space complexity - O(n)
vector<int> dailyTemperatures_old(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0); 
    for (int i = 0; i<n; i++) { 
        for (int j = i+1; j<n; j++) { 
            if (temperatures[j] > temperatures[i]) { 
                ans[i] = j - i;
                break;
            }
        }
    }

    return ans; 
}

// Push a index into stack. and move ahead if a greaute temp found pop back prev elements by comparing 
// Monotonic stack implementation 
// Better approach using a stack
// Hint for using monotonic stack here -
// That is a classic "next greater element" pattern.

// When you see something like:

// next smaller
// next greater
// previous greater
// previous smaller
// first greater element to the right/left
// nearest smaller element
// nearest greater element
// your brain should immediately consider: Monotonic stack
// Then ask:

// "Am I repeatedly searching through elements I've already looked at?"
// If yes, look for a data structure that lets you remember useful unresolved elements.
// For "next greater/smaller" problems, that structure is usually a monotonic stack.
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i=0; i<n; i++) {

        while (!s.empty())  {
            if (temperatures[i] > temperatures[s.top()])
            {
                int diff = i - s.top();
                ans[s.top()] = diff;
                s.pop();
            }
            else
            {
                break; // because we are finding prev lesser ele for every element.
            }
        }
        s.push(i);
    }

    return ans; 
}


int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (int  x : ans) { 
        cout << x << " ";
    }
    cout << endl;
}