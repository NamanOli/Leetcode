// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// https://www.geeksforgeeks.org/longest-sub-array-sum-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int mx = 0;
        unordered_map<int, int> mp;
        int currsum=0;
        
        for(int i=0;i<n;i++)
        {
            currsum+=arr[i];
            if(currsum==k)
            {
                mx = max(mx, i+1);
            }
            if(mp.find(currsum-k)!=mp.end())
            {
                int in = mp[currsum-k];
                mx = max(mx, i-in);
            }
            if(mp.find(currsum)==mp.end())
                mp[currsum]=i;
        }
        return mx;
        
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
