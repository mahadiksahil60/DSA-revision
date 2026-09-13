#include<bits/stdc++.h>
using namespace std; 

// Approach : Find a way to turn a array into string and then be able to reconstruct the array from the string.
// Solution :
// 1) for each element, calulate the number of letter in it and append it at the start so we know how to reconstruct that element 
// 2) Put # after every element just to know distiction (optional)
// 3) While reconstructing check if the current char is digit if it is then run a loop for that amount and construct a element and push it into ans array 
string encode(vector<string>& strs) {
    int n = strs.size();
    string encoded_string = "";
    for (int i=0; i<n; i++) {
        int len = strs[i].size();
        string letters = to_string(len);
        encoded_string += letters;
        encoded_string += strs[i];
        encoded_string += "#";
    }

    return encoded_string;
}

vector<string> decode(string s) {
    int n = s.length();
    vector<string> ans; 
    int i = 0; 
    while (i < n) {
        int j = i; 

        int temp_counter = 0;

        if (isdigit(s[i]))  { // New NOTE IMP : this is the function used to know if the char at hand is digit or not. 
            string character_as_string(1, s[i]); // This is the function to convert from char to string.
            int number = stoi(character_as_string); // This is the function that is used to convert from string to number.
            string temp;
            int bound = number + i;
            for (int j=i+1; j <= bound; j++) {
                 temp += s[j];
                 i++;
            }
            ans.push_back(temp);
        }
        
        i++;
    }

    return ans;
}

int main() { 
   vector<string> strs = {"Hello","World","Program"};
   string ans = encode(strs);
   cout << "encoded string : " << ans << endl;
   vector<string> decoded_string = decode(ans);
   for (string s : decoded_string) { 
    cout << s << endl;
   }
} 