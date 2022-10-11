class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int a=INT_MAX,b=INT_MAX;
        for(auto i:nums)
        {
            if(i<=a)
            {
                a=i;
            }
            else if(i>a&&i<=b)
            {
                b=i;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
};