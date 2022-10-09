https://leetcode.com/problems/letter-case-permutation/

https://www.youtube.com/watch?v=4eOPYDOiwFo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16

```
class Solution {
public:
    void solve(vector<string> &ans, string ip, string op){
        if(ip.length()==0)
        { // if input is all covered then put output in the answer
            ans.push_back(op);
            return ;
        }
        
        if(isdigit(ip[0]))
        { // if it is a digit do nothing just insert in the output
            string opx = op; // 
            opx.push_back(ip[0]); // add the digit to the answer
            ip.erase(ip.begin()+0); // erase the digit from the input
            solve(ans,ip,opx); // call the function with the new input
        }
        
        else
        { // if it is a alphabet
        string op1 =op;
        string op2 =op;
        op1.push_back(tolower(ip[0])); // one case will be the capital case
        op2.push_back(toupper(ip[0])); // one case will be the lower case so convert it to the capital case
        ip.erase(ip.begin()+0); // remove the alphabet from the input
        solve(ans,ip,op1); // call the function with new output
        solve(ans,ip,op2); 
        }
    }
    vector<string> letterCasePermutation(string s) {
         vector<string> ans;
        solve(ans,s,"");
         return ans;
    }
};
```
