#include<bits/stdc++.h>
using namespace std; 


// Approach 1 : use two freq maps and match the freq if yes then anagram if no return false.

// Time complexity : O(n + n + k)
// space complexity : O(k) where k is the number of distinct characters.
bool isAnagram_v1(string s, string t) {
    
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

// Approach 2 : Using sorting 
// Time complexity : O(nlogn) due to sorting 
// Space complexity :  O(nlogn) for sorting the input arrays. 
bool isAnagram_v2(string s, string t) {
    if (s.size() != t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i = 0; 
    
    while(i < s.size())  { 
        if (s[i] != t[i]) { 
            return false;
        }
        i++;
    }
    return true;
}

// Approach 3 : Using the 1st approch but a NOTE : fixed array instead of the hash map to optimize space complexity
bool isAnagram(string s, string t) { 
    if (s.size() != t.size()) return false;
    int freq[26] = {0};
    for (int i=0; i<s.size(); i++) {
        freq[s[i] - 'a']++; // increment in the array when the element is encountered in string s
        freq[t[i] - 'a']--; // decrement in the array if same element is encountered in string t
    }

    // at the end all the freqs of the alphabets should be zero indicating an anagram
    for (int i = 0; i < 26; i++) { 
        if (freq[i] != 0) {
            return false; 
        }
    }
    return true;
}



int main() { 
    string s = "anagra";
    string t = "nagaram";
    cout << "hello" << endl;
    bool ans = isAnagram(s, t);
    cout << ans << endl;
}