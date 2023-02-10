#define ll long long 
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll n=ideas.size();
        vector<vector<string>> v(26);
        set<string> st;
        for(auto &idea:ideas)
        {
            st.insert(idea);
        }
        set<char> ch;
        vector<char> chh;
        
        for(ll i=0;i<n;i++)
        {
            ch.insert(ideas[i][0]);
            v[ideas[i][0]-'a'].push_back(ideas[i]);
        }
        for(auto &x:ch)
        {
            chh.push_back(x);
        }
        ll ans=0;
        for(ll i=0;i<chh.size();i++)
        {
            for(ll j=i+1;j<chh.size();j++)
            {
                char x=chh[i],y=chh[j];

                if(x==y)continue;
                if(v[x-'a'].size()>0&&v[y-'a'].size()>0)
                {
                    ll c1=0;
                    ll c2=0;
                    for(auto &s:v[x-'a'])
                    {
                        string z=s;
                        z[0]=y;
                        if(st.find(z)==st.end())
                        {
                            c1++;
                        }
                    }
                    for(auto &s:v[y-'a'])
                    {
                        string z=s;
                        z[0]=x;
                        if(st.find(z)==st.end())
                        {
                            c2++;
                        }
                    }
                    ans+=2*c1*c2;
                }
            }
        }
        return ans;
    }
};