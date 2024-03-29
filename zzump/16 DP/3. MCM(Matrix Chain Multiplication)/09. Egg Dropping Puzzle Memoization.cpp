// https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int dp[201][201];
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k)
    {
        if(k==0||k==1)
        {
            dp[n][k]==0;
            return k;
        }
        if(n==1)
        {
            dp[n][k]==0;
            return k;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int mn=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int temp=1+max(eggDrop(n-1,i-1),eggDrop(n,k-i));
            mn=min(mn,temp);
        }
        dp[n][k] = mn;
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return (solve(n,k));
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
 
