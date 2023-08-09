The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

class Solution {
public:
    int min(int x,int y) {
        return x<y?x:y;
    }
    string convert(string s, int numRows) {
	int row_count = min(numRows, s.length());
	vector<string> rows(row_count);

	if (numRows == 1) {
		return s;
	}
	// Divide source string into number of rowStrings
	bool goingDown = true;
	size_t count = 0;
	int rowIndex = 0;
	for (size_t i = 0; i<s.length(); i++) {
		rows[rowIndex] += s[i];
		if (goingDown) {
			rowIndex++;
			if (rowIndex == row_count) {
				goingDown = false;
				rowIndex = rowIndex - 2;
			}
		}
		else {
			rowIndex--;
			if (rowIndex<0) {
				goingDown = true;
				rowIndex = 1;
			}
		}
	}

	string result = "";
	for (string r : rows) {
		result += r;
	}
	return result;
}
};