https://leetcode.com/problems/valid-anagram/

https://leetcode.com/problems/valid-anagram/discuss/66519/2-C%2B%2B-Solutions-with-Explanations

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i:mp)
        {
            if(i.second!=0)
                return false;
        }
        return true;
    }
};
```
