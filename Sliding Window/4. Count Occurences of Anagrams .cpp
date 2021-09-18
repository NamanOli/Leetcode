// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string ana, string s) {
	    // code here
	    	    unordered_map<char, int> m;
    for(auto it : ana) m[it]++;

    int k=ana.length();
    int count=m.size();
    
    int i=0, j=0;
    int ans=0;
    
    while(j<s.length()){
    
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
        
        if((j-i+1)<k) j++;
        
        else if((j-i+1)==k){

            if(count==0) ans++;

            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
