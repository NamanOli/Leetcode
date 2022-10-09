https://practice.geeksforgeeks.org/problems/maximum-product-of-increasing-subsequence-of-size-32027/1#

https://www.geeksforgeeks.org/maximum-product-increasing-subsequence-size-3/

```
class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        set<int>st;
        st.insert(arr[0]);
        vector<int>dp(n , 0);
        dp[n - 1] = arr[n - 1];
        for(int i = n -2 ; i >= 0 ; i--)
        dp[i] = max(arr[i] , dp[i + 1]);
        vector<int>ans;
        long long int maxprod = 1;
        for(int i = 1 ; i < n - 1 ; i++){

            int third = dp[i + 1];
            auto it = st.lower_bound(arr[i]);
            if(it == st.begin()){
                st.insert(arr[i]);
                continue;
            }
            it--;
            int first = *it;
            st.insert(arr[i]);
            if(first < arr[i] && arr[i] < third && first *1LL * arr[i] * 1LL * third >= maxprod){
                maxprod = first *1LL * arr[i] * 1LL * third ;
                ans = {first , arr[i] , third};
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
        }
        return ans;
        
    } 

};
```
