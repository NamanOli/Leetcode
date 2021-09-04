// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    
	    long long  dp[M+1][V+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=M;i++)
	    {
	        for(int j=0;j<=V;j++)
	        {
	           if( j==0)
	           dp[i][j]=0;
	           else if(i==0)
	           dp[i][j]=INT_MAX;
	           else
	           {
	               if(coins[i-1]<=j)
	               dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	               else
	               dp[i][j]=dp[i-1][j];
	           }
	        }
	    }
	 return dp[M][V]==INT_MAX?-1:dp[M][V];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
