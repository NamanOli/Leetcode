class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) {
            return chars.size();
        }

        string s;

        int i=0,j=1;

        while(i<chars.size()) {
            s.push_back(chars[i]);

            int count=1;

            while(j<chars.size() && chars[j]==chars[i]) {
                count++;
                j++;
            }
            if(count>1) {
                s+=to_string(count);
            }
            i=j;
            j++;
        }

        chars.clear();

        for(auto i:s) {
            chars.push_back(i);
        }
        return chars.size();
    }
};