// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
         // Your code here
       int i,j; // i is n j is w
       int dp[n+1][W+1];
        for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] +
                                dp[i ][j - wt[i - 1]],
                                dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
