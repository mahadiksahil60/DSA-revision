#include <bits/stdc++.h>
using namespace std;

class MinStack {

private:    
    vector<int> stack;  // This is used to store actual elements,
    vector<int> minStack; // This is used to maintain the min element at every level.
MinStack() {
    
}

// insert the element in the stack and check if the this value is min than the back of minStack if yes push 
void push(int value) {
    stack.push_back(value);

    if (minStack.empty() || value <= minStack.back()) {
        minStack.push_back(value);
    }
}

// pop the last element and if the element exists in minStack pop that as well
void pop() {
    // popping from minStack 
    if (stack.back() == minStack.back()) { 
        minStack.pop_back();
    }
    stack.pop_back(); // vector function to remove last element. 
}

int top() {
    return stack.back();
}

int getMin() {
    return minStack.back();
}

};