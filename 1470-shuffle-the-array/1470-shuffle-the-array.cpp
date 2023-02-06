class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        queue<int> q; 
        for(int i=0; i< n-1; i++) {
            // save alternate postions
            q.push(nums[2*i+1]);
            q.push(nums[2*i+2]);

            // at odd postion we'll have y1 .. yn
            nums[2*i+1] = nums[n+i];
            // at even position we'll have x1.. xn
            nums[2*i+2] = q.front();
            q.pop();
        }

        return nums;
    }
};