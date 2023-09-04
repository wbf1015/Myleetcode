class Solution {
public:
    int count_rob(vector<int>& nums){
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
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        if(nums.size()==3){
            return max(nums[0], max(nums[1],nums[2]));
        }
        // 第一种情况是抢头，那第一个，第二个和最后一个都不能抢了
        vector<int>situ1(nums.begin()+2,nums.end()-1);
        int situ1_ret = nums[0] + count_rob(situ1);
        // 第二种情况是不抢头，那好办，第二个和最后一个都可以抢，相当于回到了最简单的那种情况
        vector<int>situ2(nums.begin()+1,nums.end());
        int situ2_ret = count_rob(situ2);
        return max(situ1_ret, situ2_ret);
    }
};