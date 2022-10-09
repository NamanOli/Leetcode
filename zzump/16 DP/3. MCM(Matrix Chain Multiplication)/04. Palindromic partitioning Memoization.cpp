// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];

    int ispalindrome(string &s ,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            
            i++;
            j--;
        }
        
        return true;
    }
   
    int solve(int i,int j ,string &s)
    {
        if( i >= j || ispalindrome(s,i,j))  {dp[i][j] = 0 ; return 0;}
        
        if(dp[i][j] != -1) return dp[i][j];
      //  if(ispalindrome(s,i,j) == true) return 0;
        int mn = INT_MAX,temp;
        for(int k = i;k< j;k++)
        {
           temp = 1 + solve(i,k,s) + solve(k+1,j,s);
           mn =  min(mn,temp);
        }
        
        dp[i][j] = mn;
        return dp[i][j];
    }

    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int n = str.size();
         return solve(0,n-1,str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
