#include <bits/stdc++.h>
using namespace std;

int give_cal(int left_operand, int right_operand, string operator_sign) { 
    if (operator_sign == "+") { 
        return left_operand + right_operand;
    }
    else if (operator_sign == "-") { 
        return left_operand - right_operand;
    }
    else if (operator_sign == "*") { 
        return left_operand * right_operand;
    }
    else{ 
        return left_operand / right_operand;
    }
}

// Apporach 1 : We insert the numbers into a stack until we encounter a opertor. once operator is received 
// pop two operands from the stack and give the calculation and push the calculated value into the stack
// this way there will always be two operands before a operator. // IMP NOTE Hint
// Solved in first attempt;
int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    int int_ans = 0;
    stack<int> s;  
    unordered_set<string> operators = {"+", "-", "/", "*"};
    for (int i=0;i<n;i++) {
        if (operators.find(tokens[i]) != operators.end()) { 
            // eleeknt is a operator do somethig 
            int right_operand = s.top();
            s.pop(); 
            int left_operand = s.top();
            s.pop();
            cout << left_operand << " " << tokens[i] << " "  << right_operand << endl;
            int ans = give_cal(left_operand, right_operand, tokens[i]);
            cout << "ans :" << ans << endl;
            s.push(ans);
            continue;
        }
        s.push(stoi(tokens[i]));
    }
    return s.top();
}


int main () { 
    vector<string> tokens = {"4","13","5","/","+"};
    int ans = evalRPN(tokens);
    cout << ans << endl;
} 