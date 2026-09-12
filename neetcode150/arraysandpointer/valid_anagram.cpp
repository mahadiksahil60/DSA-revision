#include<bits/stdc++.h>
using namespace std; 


// Approach 1 : use two freq maps and match the freq if yes then anagram if no return false.
bool isAnagram(string s, string t) {
    
    // use freq map
    unordered_map<char, int> freqMap;
    unordered_map<char, int> freqMap2;
    
    if (s.length() != t.length()) return false;
    // This loop for storing every element in the freq map 
    for (int i = 0; i < s.length(); i++) { 
        freqMap[s[i]]++;
    };

    // this loop for storing every element of the second string 
    for (int i=0;i<t.length(); i++) { 
        freqMap2[t[i]]++;
    }

    for (const auto& pair : freqMap) {
        auto it = freqMap2.find(pair.first);
        
        // Check if the key is missing or if the values don't match
        if (it == freqMap2.end() || it->second != pair.second) {
            return false;
        }
    }

    return true;
}

int main() { 
    string s = "anagram";
    string t = "nagaram";
    cout << "hello" << endl;
    bool ans = isAnagram(s, t);
    cout << ans << endl;
}