#include <bits/stdc++.h>
using namespace std;

/// @brief Appraoch 1 : create a stack and an unordered map for storing opp pair of brackets. 
// thorugh a loop insert if its a opening brancket. if its a closing brached, check if a corresponting closing branked exists in the mop
/// @param s
/// @return
bool isValid(string s) {
    stack<char> st;
	unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
	for (char c : s) { 
		if (c == '{' || c == '[' || c == '(') { 
			st.push(c);
		}
		else { 
			if (st.empty() || st.top() != match[c]) return false;
			st.pop();
		}
	}

	return st.empty();
}

int main()
{
	string s = "()";
	bool ans = isValid(s);
	cout << ans << endl;
	cout <<"EOL"<<endl;
}