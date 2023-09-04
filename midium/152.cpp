#include <iostream>
#include <vector>
#include<string>

using namespace std;


// 这道题思考了挺久的，局部最优解不是全局最优解
// 题解里那句话很重要：对于正数我们希望他越大越好，对于负数我们希望他越小越好
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int max_dp[20001] = {0}; max_dp[0] = nums[0];
        int min_dp[20001] = {0}; min_dp[0] = nums[0];
        int ret = max_dp[0];
        for(int i=1;i<nums.size();i++){
            max_dp[i] = max(max_dp[i-1]*nums[i], max(nums[i], min_dp[i-1]*nums[i]));
            min_dp[i] = min(min_dp[i-1]*nums[i], min(nums[i], max_dp[i-1]*nums[i]));
            ret = max(ret,max_dp[i]);
        }
        return ret;
    }
};