![image](https://user-images.githubusercontent.com/53824950/163578480-7955051a-6fe7-475f-8146-7aef083aca37.png)

https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

https://leetcode.com/problems/longest-palindromic-substring/

![image](https://user-images.githubusercontent.com/53824950/163579227-5242c7f2-ba71-4c4c-95a8-95812210cb5a.png)

https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

```
class Solution {
public:
    string longestPalindrome(string str) {
      // get length of input string
    int n = str.size();
 
    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
 
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1;
 
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    return str.substr(start,maxLength);
    }
};
```
Complexity Analysis:  

Time complexity: O(n^2). 
Two nested traversals are needed.
Auxiliary Space: O(n^2). 
Matrix of size n*n is needed to store the dp array.
