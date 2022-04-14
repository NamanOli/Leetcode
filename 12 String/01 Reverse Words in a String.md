https://leetcode.com/problems/reverse-words-in-a-string/

```

class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        s+=" ";
        string str="";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]==' ')
            {
                st.push(str);
                str="";
            }
            else
            {
                str+=s[i];
            }
        }
        string ans="";
        while(st.size()!=1)
        {
            ans+=st.top()+" ";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        if(ans[0]==' ')
            ans=ans.substr(1,ans.size());
        if(ans[ans.size()-1]==' ')
                        ans=ans.substr(0,ans.size()-1);
        return ans;
        

    }
};
```

```
class Solution {
public:
    void reverseWords(string &s) {
        int sz = s.size();
        int i = 0, j = 0;
        while (i < sz)
        {
            while (i < sz && s[i] == ' ') i++; //i is the start of the word
            if (i < sz && j > 0)
                s[j++] = ' ';
            int start = j;
            while (i < sz && s[i] != ' ')
                s[j++] = s[i++];
            reverse(s.begin()+start, s.begin()+j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
    }
};
```

