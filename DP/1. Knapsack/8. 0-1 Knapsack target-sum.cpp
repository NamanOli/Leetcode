// https://leetcode.com/problems/target-sum/


// this cpp solution is accepted on leetcode:
// 1. By multiplying pow(2,cnt), it will consider all the subsets of 0 which was not considered earlier.
// 2. one more condition needs to be checked i.e.if((S+sum)%2!=0)  then  we would never get the difference S by partitioning the array into two subsets.
// Basically s1-s2 = diff  equation 1
// and s1+s2 = sum   equation 2
// This gives 2s1 = sum+diff => s1 = (sum+diff)/2
// So, if (sum+diff) is even then only finding s1 is possible.
// Cnt is for '0's in the array. If we have n number of zeroes then we need to multiply out result of count of subsets with a sum to 2^n.  And we need to not consider this while calculating in bottom-up manner, hence the case " if(nums[i-1]==0) { dp[i][j] = dp[i-1][j] } ".
// For example: If we have 2(cnt=2) zeroes in the example array for which we calculate count of subset with a sum then there are 4(2^cnt) ways that is either selecting first zero, second selecting second 0 present in array, third not selecting both, fourth selecting both.
// Hope this will be helpful.
class Solution {
public:
    int subset(vector<int>nums,int sum){
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int j=1;j<=sum;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        s=accumulate(nums.begin(),nums.end(),s);
        int p=(target+s)/2;
        if(s < target || (s + target) % 2 != 0)
            return 0;
        return subset(nums,abs(p));   
    }
};
