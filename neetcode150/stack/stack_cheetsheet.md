# C++ Stack Cheatsheet

A complete reference for `std::stack` and stack-based problem solving in C++.

---

## 1. Header & Declaration

```cpp
#include <stack>
using namespace std;

stack<int> s;                     // default: uses deque as underlying container
stack<int, vector<int>> s2;       // stack backed by vector
stack<int, list<int>> s3;         // stack backed by list
```

`std::stack` is a **container adapter** — it doesn't implement its own data structure, it wraps another container (`deque` by default, or `vector`/`list`) and only exposes LIFO (Last In, First Out) operations.

---

## 2. Core Operations

| Operation      | Description                          | Time Complexity |
|----------------|---------------------------------------|------------------|
| `s.push(x)`    | Insert `x` on top                     | O(1) amortized   |
| `s.pop()`      | Remove top element (no return value)  | O(1)             |
| `s.top()`      | Access top element (reference)        | O(1)             |
| `s.empty()`    | Check if stack is empty               | O(1)             |
| `s.size()`     | Number of elements                    | O(1)             |
| `s.emplace(x)` | Construct element in-place on top     | O(1) amortized   |
| `s.swap(s2)`   | Swap contents with another stack      | O(1)             |

> ⚠️ `pop()` does NOT return the removed element. Always call `top()` before `pop()` if you need the value.

```cpp
stack<int> s;
s.push(10);
s.push(20);
s.push(30);

cout << s.top();  // 30
s.pop();          // removes 30
cout << s.top();  // 20
cout << s.size(); // 2
cout << s.empty(); // 0 (false)
```

---

## 3. Iterating Through a Stack (Destructive)

`std::stack` has **no iterators** — you cannot loop through it directly. To view/process all elements you must pop them (or copy the stack first if you need to preserve it).

```cpp
stack<int> s;
s.push(1); s.push(2); s.push(3);

while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
// Output: 3 2 1
```

To preserve the original stack, copy it first:

```cpp
stack<int> copy = original;   // copy constructor
while (!copy.empty()) {
    cout << copy.top() << " ";
    copy.pop();
}
```

---

## 4. Building a Stack From a Vector/Array

```cpp
vector<int> v = {1, 2, 3, 4, 5};
stack<int> s(deque<int>(v.begin(), v.end()));
// top of stack will be 5
```

Or just push in a loop:

```cpp
stack<int> s;
for (int x : v) s.push(x);
```

---

## 5. Custom Stack Implementation (Array-Based)

Useful for interviews or when you need full control.

```cpp
class Stack {
    vector<int> data;
    int capacity;

public:
    Stack(int cap) : capacity(cap) {}

    void push(int x) {
        if ((int)data.size() >= capacity) throw overflow_error("Stack Overflow");
        data.push_back(x);
    }

    void pop() {
        if (isEmpty()) throw underflow_error("Stack Underflow");
        data.pop_back();
    }

    int top() {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return data.back();
    }

    bool isEmpty() { return data.empty(); }
    int size() { return data.size(); }
};
```

---

## 6. Custom Stack Implementation (Linked List-Based)

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
    Node* head = nullptr;
    int count = 0;

public:
    void push(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
        count++;
    }

    void pop() {
        if (isEmpty()) throw underflow_error("Stack Underflow");
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    int top() {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return head->data;
    }

    bool isEmpty() { return head == nullptr; }
    int size() { return count; }

    ~LinkedStack() {
        while (!isEmpty()) pop();
    }
};
```

---

## 7. Min Stack (Get Minimum in O(1))

Common interview problem: design a stack that supports `push`, `pop`, `top`, and `getMin()` all in O(1).

```cpp
class MinStack {
    stack<long long> st;
    long long minVal;

public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minVal = x;
        } else if (x >= minVal) {
            st.push(x);
        } else {
            st.push(2LL * x - minVal); // encode
            minVal = x;
        }
    }

    void pop() {
        if (st.top() < minVal) {
            minVal = 2LL * minVal - st.top(); // decode previous min
        }
        st.pop();
    }

    int top() {
        return st.top() < minVal ? minVal : st.top();
    }

    int getMin() {
        return minVal;
    }
};
```

Alternative simpler version using two stacks (uses more space, easier to understand):

```cpp
class MinStack {
    stack<int> st, minSt;

public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) minSt.push(x);
        else minSt.push(minSt.top());
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};
```

---

## 8. Classic Stack Problems & Patterns

### 8.1 Balanced Parentheses

```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

### 8.2 Next Greater Element (Monotonic Stack)

```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

### 8.3 Previous Smaller Element

```cpp
vector<int> prevSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}
```

### 8.4 Largest Rectangle in Histogram

```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> st; // indices, increasing heights
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

### 8.5 Evaluate Postfix Expression

```cpp
int evalPostfix(string tokens[], int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        string& t = tokens[i];
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}
```

### 8.6 Infix to Postfix Conversion

```cpp
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        } else { // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
```

### 8.7 Reverse a Stack (Using Recursion, No Extra Stack)

```cpp
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}
```

### 8.8 Sort a Stack (Using Recursion)

```cpp
void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}
```

### 8.9 Implement Queue Using Two Stacks

```cpp
class MyQueue {
    stack<int> inStack, outStack;

    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
```

### 8.10 Implement Stack Using Two Queues

```cpp
class MyStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
```

### 8.11 Stock Span Problem

```cpp
vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // indices, decreasing price order

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return span;
}
```

### 8.12 Trapping Rain Water (Stack Approach)

```cpp
int trap(vector<int>& height) {
    stack<int> st; // indices
    int water = 0, i = 0;

    while (i < (int)height.size()) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }
        st.push(i++);
    }
    return water;
}
```

### 8.13 Remove K Digits to Form Smallest Number

```cpp
string removeKdigits(string num, int k) {
    string st; // using string as a stack

    for (char c : num) {
        while (!st.empty() && k > 0 && st.back() > c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    while (k-- > 0) st.pop_back(); // remove remaining from end

    int start = 0;
    while (start < (int)st.size() - 1 && st[start] == '0') start++;
    st = st.substr(start);

    return st.empty() ? "0" : st;
}
```

### 8.14 Celebrity Problem (Stack Approach)

```cpp
// M[i][j] = 1 means i knows j
int findCelebrity(vector<vector<int>>& M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);

    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (M[a][b]) st.push(b); // a knows b, so a can't be celebrity
        else st.push(a);         // b knows a (or doesn't), a might be celebrity
    }

    int candidate = st.top();
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] || !M[i][candidate]) return -1;
        }
    }
    return candidate;
}
```

---

## 9. Monotonic Stack Template (Memorize This)

The pattern behind Next Greater/Smaller Element problems:

```cpp
// Next Greater Element to the right
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
        // st.top() found its "next greater" = arr[i]
        st.pop();
    }
    st.push(i);
}

// Next Smaller Element to the right: flip comparison to >
// Previous Greater/Smaller: iterate array in reverse, or track ans as you go
```

| Goal                          | Iterate | Condition to pop         |
|-------------------------------|---------|----------------------------|
| Next Greater Element (right)  | left→right | `arr[st.top()] < arr[i]` |
| Next Smaller Element (right)  | left→right | `arr[st.top()] > arr[i]` |
| Previous Greater Element      | right→left | `arr[st.top()] < arr[i]` |
| Previous Smaller Element      | right→left | `arr[st.top()] > arr[i]` |

---

## 10. Complexity Summary

| Structure                     | Push | Pop  | Top  | Space |
|--------------------------------|------|------|------|-------|
| `std::stack` (deque-backed)    | O(1)*| O(1) | O(1) | O(n)  |
| Array-based custom stack       | O(1)*| O(1) | O(1) | O(n)  |
| Linked-list-based custom stack | O(1) | O(1) | O(1) | O(n)  |

\* amortized (occasional resize)

---

## 11. Common Pitfalls

- Calling `top()` or `pop()` on an **empty stack** → undefined behavior. Always check `empty()` first.
- Forgetting `pop()` doesn't return a value — save `top()` before popping.
- Using `std::stack` when you need iteration/indexing — use `vector` instead in that case.
- Off-by-one errors in monotonic stack width calculations (`i - st.top() - 1`).
- Stack overflow from deep recursion (e.g., reversing/sorting a stack recursively on very large inputs).

---

## 12. Quick Reference Card

```cpp
#include <stack>
stack<int> s;

s.push(x);      // add to top
s.pop();        // remove top (no return)
s.top();        // peek top
s.empty();      // true/false
s.size();       // count
s.emplace(x);   // construct in-place
```