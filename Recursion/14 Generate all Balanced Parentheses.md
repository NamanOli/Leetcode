https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17

https://www.interviewbit.com/problems/generate-all-parentheses-ii/

```
void solve(vector<string>& result, int open, int close, string curr) 
{
        if(open == 0 && close==0) 
        {
            result.push_back(curr);
            return;
        }
        if(open!=0) // in this case ( will come always
            solve(result, open-1, close, curr+'('); // decrease open count
        if(close>open)
            solve(result, open, close-1, curr+')'); // decrease close count
}

vector<string> Solution::generateParenthesis(int A) 
{
    vector<string>result;
    int open=A;
    int close=A;
    string curr="";
    solve(result,open,close,curr);
    return result;
}

```
