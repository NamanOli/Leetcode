https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1#

```
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>res;
        int curr_idx=a[n-1];
        res.push_back(curr_idx);
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>=curr_idx)
            {
                res.push_back(a[i]);
                curr_idx=a[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

Time - O(N)
```

```
- Create vector of result 
- Push the last element to the res vector and initalize as curr
- traverse fron the second last till 0
- If the arr[i] is greater than curr  then update curr and push element to res
- return res
```
