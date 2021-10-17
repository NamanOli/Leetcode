//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
/* Put i=0,j=0 and increment j++. Now store the characters i.e. s[j] in a map and map[s[j]]++. Now calculate map.size(), if it is less than k j++ else if it is equal to k
store it in a variable mx which will store j-i+1 . if map.size() becomes greater than k then i++ and map[s[i]]--.
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     int i=0; int j= 0;
       int mx=-1;
       unordered_map<char,int>mp;
       while(j<s.size()){
           mp[s[j]]++;
           
           if(mp.size()==k){
               mx= max(j-i+1, mx);
               }
               if(mp.size()>k){
                   mp[s[i]]--;
                   if(mp[s[i]]==0)
                   mp.erase(s[i]);
                   i++;
               }
               j++;
               
       }
       return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
