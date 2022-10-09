https://leetcode.com/problems/trapping-rain-water/



![image](https://user-images.githubusercontent.com/53824950/163769157-4803c7a7-2da7-4ebe-8893-59d1e83cfb7e.png)

![image](https://user-images.githubusercontent.com/53824950/163769340-dfad77f7-733e-4622-a876-046ec881e783.png)

```
Brute -
- For each element in array ,find the left max and right max 
- the area of waster contained will be min(leftmax,rightmax)-arr[i]
```

![image](https://user-images.githubusercontent.com/53824950/163769870-e79de245-40b6-4d85-80ef-1390c16ce7a9.png)

![image](https://user-images.githubusercontent.com/53824950/163769981-2b8bfac2-9f1e-4554-aaf6-07a044b64514.png)

```
Optimized - 
- For calculating left max and right max we can use prefix sum arrays
- Traverse from 0 to n and keep updating max till now
```

![image](https://user-images.githubusercontent.com/53824950/163771118-aa5212d8-1721-4721-be0d-2662d4f2048d.png)

```
Most Optimized - 
- Take 4 pointer left , right, maxleft, maxright
- while left <= right

- if height[right]>=height[left], means we cannot take right part as we know we have to take minimum of left and right so that will be left part
- if height[left] greater than max left then update maxleft
- else the height is less than maxleft so that will add up to the result=maxleft-height[left]

- else 
- do the same as in height[left]

- finally return result
```
```
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int res=0;
        int maxleft=0,maxright=0;
        while(left<=right)
        {
            if(height[right]>=height[left])
            {
                if(height[left]>=maxleft)maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else
            {
                if(height[right]>=maxright)maxright=height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};
```
