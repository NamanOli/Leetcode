// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int solve(int arr[],int i,int j)
    // {
    //     if(i>=j)
    //     {
    //         return 0;
    //     }
    //     int mn=INT_MAX;
    //     for(int k=i;k<=j-1;j++)
    //     {
    //         int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
    //         if(tempans<mn)
    //         {
    //             mn=tempans;
    //         }
    //     }
    //     return mn;
    // }
    int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate count of multiplications for
    // each parenthesis placement and return the
    // minimum count
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}
    int matrixMultiplication(int N, int arr[])
    {
        
        return MatrixChainOrder(arr,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
