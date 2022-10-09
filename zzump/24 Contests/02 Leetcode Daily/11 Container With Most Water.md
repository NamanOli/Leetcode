https://leetcode.com/problems/container-with-most-water/

https://leetcode.com/problems/container-with-most-water/discuss/1915172/JavaC%2B%2B-Easiest-Explanations

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxi=0;
        while(left<right)
        {
            int width=right-left;
            int area=width*min(height[left],height[right]);
            maxi=max(maxi,area);
            if(height[left]<height[right])
            {
                left++;
            }
            else if(height[left]>height[right])
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }
        return maxi;
    }
};
```
