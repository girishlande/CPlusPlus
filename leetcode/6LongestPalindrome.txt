Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string s) {
	size_t len = s.length();
	for (size_t i = 0; i<len / 2; i++) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

string longestPalindrome(string s) {
	if (s.length() == 1)
		return s;
	string ls = "";
	for (size_t i = 0; i<s.length(); i++) {
		for (size_t j = s.length() - i; j>0; j--) {
			string r = s.substr(i, j);
			if (isPalindrome(r)) {
				if (r.length()>ls.length())
					ls = r;
			}
		}
	}
	return ls;
}

int main()
{
	string s = "bsnetpqmwhqjunkooftuosgkmkxpmvuehtlpwpktltwlvpdaycnhewdbdrhluyjldecezujgxixehsmjjuyerpllrvzqskizkulqzowzfvqcdsllvgupndbaiuzihcxklvxbodpnrymwobhlvllybdlfabfvnizjpriapuzszdhohfgezayokrivbgbgingspoxsridokhwekawchjdcpylvefubulvxneuizglrjktfcdirwnpqztdpsicslzaeiaibrepifxpxfkczwoumkkuaqkbjhxvasxflmrctponwwenvmtdaqaavubyrzbqjbjxpejmucwunanxwpomqyondyjuzxmzpevxqmbkrwcpdiiph";
	std::cout << longestPalindrome(s);
    return 0;
}


// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

/* Returns LCS X and Y */
string lcs(string &X, string &Y)
{
	int m = X.length();
	int n = Y.length();

	vector<vector<int>> L(m+1, vector<int>(n+1));
	//int L[m + 1][n + 1];

	/* Following steps build L[m+1][n+1] in bottom
	up fashion. Note that L[i][j] contains
	length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];

	// Create a string length index+1 and
	// fill it with \0
	string lcs(index + 1, '\0');

	// Start from the right-most-bottom-most
	// corner and one by one store characters
	// in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y
		// are same, then current character
		// is part of LCS
		if (X[i - 1] == Y[j - 1])
		{
			// Put current character in result
			lcs[index - 1] = X[i - 1];
			i--;
			j--;

			// reduce values of i, j and index
			index--;
		}

		// If not same, then find the larger of
		// two and go in the direction of larger
		// value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	return lcs;
}

// Returns longest palindromic subsequence
// of str
string longestPalindrome(string &str)
{
	// Find reverse of str
	string rev = str;
	reverse(rev.begin(), rev.end());

	// Return LCS of str and its reverse
	return lcs(str, rev);
}

int main()
{
	string s = "bsnetpqmwhqjunkooftuosgkmkxpmvuehtlpwpktltwlvpdaycnhewdbdrhluyjldecezujgxixehsmjjuyerpllrvzqskizkulqzowzfvqcdsllvgupndbaiuzihcxklvxbodpnrymwobhlvllybdlfabfvnizjpriapuzszdhohfgezayokrivbgbgingspoxsridokhwekawchjdcpylvefubulvxneuizglrjktfcdirwnpqztdpsicslzaeiaibrepifxpxfkczwoumkkuaqkbjhxvasxflmrctponwwenvmtdaqaavubyrzbqjbjxpejmucwunanxwpomqyondyjuzxmzpevxqmbkrwcpdiiph";
	std::cout << longestPalindrome(s);
    return 0;
}


