// https://practice.geeksforgeeks.org/problems/https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#1642/1#

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<int> dp;
    int fun(int n, int x, int y, int z){
        if(n == 0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MIN;
        if(n>=x){
            ans = max(ans,1+fun(n-x,x,y,z));
        }
        if(n>=y){
            ans = max(ans,1+fun(n-y,x,y,z));
        }
        if(n>=z){
            ans = max(ans,1+fun(n-z,x,y,z));
        }
        //if(ans == INT_MIN) return dp[n] = INT_MIN;
        return dp[n] =  ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        dp.resize(n+1,-1);
        int ans = fun(n,x,y,z);
        return ans<0?0:ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
