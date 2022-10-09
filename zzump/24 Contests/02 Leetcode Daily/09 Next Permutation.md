https://leetcode.com/problems/next-permutation/


```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int indx1,indx2;
        for(int i=len-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                indx1=i;
                break;
            }
        }
        if(indx1<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=len-1;i>indx1;i--)
        {
            if(nums[i]>nums[indx1])
            {
                indx2=i;
                break;
            }
        }
        swap(nums[indx1],nums[indx2]);
        reverse(nums.begin()+indx1+1,nums.end());
        }
        
    }
};
```
