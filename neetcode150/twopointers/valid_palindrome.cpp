#include <bits/stdc++.h>
using namespace std;

// Utility
bool isLetter(char c)
{
	return isalnum(static_cast<unsigned char>(c));
}

// Approach 1 : remove the spaces and special characcters and then run two pointers i and j in opp direction and check if both char's match
// Time complexity approax = O(2n) -> O(n) for large inputs || Space complexity - O(n)
// Can be optimized for space complexity
bool isPalindrome_old(string s)
{
	string temp;
	// 1st loop for removing chars
	for (char c : s)
	{
		if (isLetter(c))
		{
			temp += tolower(c);
		}
	}

	int i = 0;
	int j = temp.length() - 1;
	while (i < j)
	{
		if (temp[i] != temp[j])
		{
			return false;
		}
		i++;
		j--;
	}

	return true;
}

// Approach 2 : Perform all the operations in a single pass
bool isPalindrome(string s)
{
	int n = s.length();
	int i = 0;
	int j = s.length() - 1;

	while (i < j && i < n && j > 0)
	{
		while (i < n && i < j && !isLetter(s[i])) // Missed in first time. Inner loops need bound too
		{
			i++;
		}
		while (j > 0 && i < j && !isLetter(s[j]))

		{
			j--;
		}

		if (tolower(s[i]) != tolower(s[j]))
		{
			return false;
		}
		i++;

		j--;
	}

	return true;
}

int main()
{
	string s = ".,";
	bool ans = isPalindrome(s);
	cout << ans << endl;
}