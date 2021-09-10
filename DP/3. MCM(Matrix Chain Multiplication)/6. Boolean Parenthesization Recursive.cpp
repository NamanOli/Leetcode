// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int recursion(string &s, int i , int j , bool isTrue){
        if(i>j) return false;
        if(i==j){
            if(isTrue == true){
                return s[i]=='T';
            }else{
                return s[i] == 'F';
            }
        }
        
        int ans = 0 ;
        for(int k = i+1 ; k < j ; k+=2){
            int lT = recursion(s,i,k-1,true);
            int lF = recursion(s,i,k-1,false);
            int rT = recursion(s,k+1,j,true);
            int rF = recursion(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue == true){
                    ans += (lT*rT); 
                }else{
                    ans += (lT*rF + lF * rT + lF *rF);
                }
            }else if(s[k] == '|'){
                if(isTrue == true){
                    ans+= (lT * rF + lF * rT + lT * rT );
                }else{
                    ans += (lF * rF);
                }
            }else{
                if(isTrue == true){
                    ans += (lT * rF + lF * rT);
                }else{
                    ans += (lT * lT + lF * rF);
                }
            }
            
        }
        return ans;
    }
    int countWays(int N, string s){
        // code here
        return recursion(s,0,s.length()-1,true);
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
