https://leetcode.com/problems/reverse-string/discuss/1901752/C%2B%2B-TWO-LINES-(-)wow!*-Explained

https://leetcode.com/problems/reverse-string/discuss/1901756/JavaC%2B%2B-3-Way's-Visual-Solution

https://leetcode.com/problems/reverse-string/


```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
	while (i < j) swap(s[i++], s[j--]);
    }
};
```
