https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/

https://leetcode.com/problems/count-and-say/discuss/16043/C%2B%2B-solution-easy-understand

https://leetcode.com/problems/count-and-say/


```
string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
```
