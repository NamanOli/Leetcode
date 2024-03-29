// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        unordered_map<char, int> mp;  
        int max_len = 0;
        int left = 0, right = 0;
        int k;
        while (right < str.size()) 
        {
            ++mp[str[right]];
            k = (right - left + 1);
            if (mp.size() == k) // all the characters in the window are unique when map size is equal to the window size
            {
                max_len = max(max_len, k); // longest window
            }
            else 
            {
                while (mp.size() < k) // some elements are repeating
                {
                    char ch = str[left];
                    --mp[ch];
                    if (mp[ch] == 0) mp.erase(ch);
                    left++;
                    k--;  // increasing left meaning window size is shrinked.
                }
                if (mp.size() == k) 
                {
                    max_len = max(max_len, k);
                }
            }  
        right++;
        }
  return max_len;
    }
};
