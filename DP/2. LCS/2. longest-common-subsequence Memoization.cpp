// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int m[1002][1002];
    int rec(int i, int j, string &s1, string &s2)
    {
        
        if(i<0 || j<0)return 0;
        if(m[i][j]!=-1)return m[i][j];
        if(s1[i] == s2[j])
        return m[i][j]= rec(i-1, j-1, s1, s2) + 1;
        else
        return m[i][j]= max(rec(i-1,j, s1,s2) , rec(i, j-1, s1,s2) );
        
    }
    int lcs(int x, int y, string s1, string s2)
    {
        memset(m , -1, sizeof(m));
        int ans = rec(s1.size()-1, s2.size()-1, s1, s2);
        return ans;
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
