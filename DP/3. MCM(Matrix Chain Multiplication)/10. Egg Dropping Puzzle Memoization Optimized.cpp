#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int t[201][201];
    int solve(int e,int f)
    {
        if(f==0||f==1)
        return f;
        if(e==1)
        return f;
        if(t[e][f]!=-1)
        return t[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int l,h;
            if(t[e-1][k-1]!=-1)
            l=t[e-1][k-1];
            else
            {
                l=solve(e-1,k-1);
                t[e-1][k-1]=l;
            }
            if(t[e][f-k]!=-1)
            h=t[e][f-k];
            else
            {
                h=solve(e,f-k);
                t[e][f-k]=h;
            }
            int temp=1+max(l,h);
            mn=min(mn,temp);
        }
        return t[e][f]=mn;
    }
    int eggDrop(int n, int k) 
    {
        t[n+1][k+1];
        memset(t,-1,sizeof(t));
        return solve(n,k);
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
