class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0, ans = 0;
        map <int,int> mp;
        while(end<fruits.size()){
           mp[fruits[end]]++;
           while(mp.size()>2){
               mp[fruits[start]]--;
               if(mp[fruits[start]]==0)
               mp.erase(fruits[start]);
               start++;
           }
           ans = max(ans,end-start+1);
           end++;
       }
        return ans;
    }
};