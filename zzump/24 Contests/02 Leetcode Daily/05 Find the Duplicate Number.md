https://leetcode.com/problems/find-the-duplicate-number/

https://leetcode.com/problems/find-the-duplicate-number/discuss/1892872/C%2B%2B-oror-Algorithm-oror-4-Approaches-oror-Binary-Search-oror-Brute-Force-oror-cnt-array-oror-map

https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

https://leetcode.com/submissions/detail/575758110/

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
```

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
};
```

Hi, some pieces of my thoughts are here, hope this would help, and if some parts are not right, plz correct me and I will appreciate that.
Since there is only one repeated number, if the number 'k' repeats once, then every number in [1, 2, ..., n] appears in array nums, the ordered array num should be [1, 2, ..., k-1, k, k, k+1, ..., n]. If there is no repeated number in the sub-array [1, ..., mid], cnt would equal to mid. In this situation, it's quite clear that cnt > mid means low < 'k' < mid, then we should scan [low, mid], and vice versa.
If the number 'k' repeats more than once, then some other numbers in [1,2, ..., n] might not appear, cause number 'k' takes over their places. We can also see that if cnt < mid, some numbers in the range [1, mid] must be replaced by the number 'k' and number 'k' beyond range [1, mid], so we should scan [mid+1, high].

