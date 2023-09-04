class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101][2]={};
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int ret = dp[0][1];
        for(int i=1;i<nums.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
            ret = max(ret,max(dp[i][0], dp[i][1]));
        }
        return ret;
    }
};