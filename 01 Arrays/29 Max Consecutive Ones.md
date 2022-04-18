https://leetcode.com/problems/max-consecutive-ones/

```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int curr =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                curr=0;
            }
            else
            {
                curr++;
                res=max(res,curr);
            }
        }
        return res;
    }
};
```

```
- If array element is 0 put curr to 0
- else increment curr and store max current in res

Time Complexity - O(N)
Space Complexity - O(1)
```
