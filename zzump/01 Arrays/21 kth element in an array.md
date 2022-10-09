https://leetcode.com/problems/kth-largest-element-in-an-array/


```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int freq=0;
        for(auto it:mp)
        {
            freq+=it.second;
            if(freq>=(n+1-k))
            {
                return it.first;
            }
        }
        return -1;
    }
};
```

```
- Create an ordered map and store the frequency of array elements
- keep on addig it.second to the freq
- traverse the array and find whether freq greater than n-k+1 as the elemts in a map will be sorted in ascending order
- finally when the above condition wsatisfies then print the it.first as it will be the kth element

Time Complexity - O(N)
Space Complexity - O(N)
```
