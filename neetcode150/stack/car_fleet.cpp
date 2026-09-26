#include <bits/stdc++.h>
using namespace std;

// Approach 1 : might need to push the hourly positions into the stack just a intuition
// irrevelant param is higher speed we have to discard it
// need to use stack

// Intution : need to calculate the time of arraival - time = (target-position)/speed. Then check if can reach with or before the ahead car. 
// Need to sort the cars from closest to farthest. 
// Check if the time taken by curr vehicle is greater means it will not be able to catch the fleet ahead so push it into the stack 
// If the time is equal or less means it can catch the fleet and therefore dont push it to the stack 
// no need to pop from the stack like conventional stack problems. 

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size(); // size will be same for the other array as well;
    if (n == 0) return 0; 
    if (n == 1) return 1; 
    stack<double> sp;
    vector<pair<int, int>> pos; 
    for (int i = 0; i<n; i++) { 
        pos.push_back({position[i], speed[i]}); 
    }
    
    // sorting according to the position
    sort(pos.begin(), pos.end(), [](const auto &a, const auto &b)
         { return a.first > b.first; }); // Logic to sort accoirding to the one of the value in the pair. 

    int i = 0;  
    while (i < n) {
        double time = (double)(target - pos[i].first) / pos[i].second;

        if (sp.empty() || time > sp.top()) {
            sp.push(time);
        }

        i++;
    }

    return sp.size(); 
}

int main() { 
    int target = 12; 
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int ans = carFleet(target, position, speed);
    cout << "ans : " << ans << endl;
}