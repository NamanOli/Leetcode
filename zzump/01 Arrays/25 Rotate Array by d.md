https://leetcode.com/problems/rotate-array/

https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        
    }
};

Time complexity: O(n)
Space complexity: O(1).
```

```
- Reverse from 0 till k
- Reverse from k till n
- Reverse the whole array
```
