// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
ll dp[2][201][201];
class Solution{
public:
ll solve(string &s,ll i, ll j,bool isrequired)
{
	if(i>j) return dp[isrequired][i][j]=false;
	
	if(i==j) // single value
	{
		if(isrequired==true)
		{
			if(s[i]=='T') 
			return dp[isrequired][i][j]=true;
			else
			return dp[isrequired][i][j]=false;
		}
		else if(isrequired==false)
		{
			if(s[i]=='F') return dp[isrequired][i][j]=true;
			else
			return dp[isrequired][i][j]=false;
		}
	}
	
	if(dp[isrequired][i][j]!=-1)
	{
	    return dp[isrequired][i][j];
	}
	
	ll ans=0;
	
	for(ll k=i+1;k<=j-1;k=k+2)
	{
		ll lt,lf,rt,rf;
		lt=solve(s,i,k-1,true)%1003;
		lf=solve(s,i,k-1,false)%1003;
		rt=solve(s,k+1,j,true)%1003;
		rf=solve(s,k+1,j,false)%1003;
		
		if(s[k]=='^')
		{
			if(isrequired==true)
			ans+=lt*rf + lf*rt;
			else
			ans+=lt*rt + lf*rf;
		}
		else if(s[k]=='&')
		{
			if(isrequired==true)
			ans+=lt*rt;
			else
			ans+=lt*rf + lf*rt + lf*rf;
		}
		else if(s[k]=='|')
		{
			if(isrequired==true)
			ans+=lt*rf + lf*rt + lt*rt;
			else
			ans+=lf*rf;
		}
		
		
	}
	
	return dp[isrequired][i][j]=ans%1003;
	
}
    int countWays(int N, string S)
    {
        // code here
        ll i,j,k;
        for(k=0;k<2;k++)
        {
            for(i=0;i<201;i++)
            {
                for(j=0;j<201;j++)
                {
                    dp[k][i][j]=-1;
                }
            }
        }
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
