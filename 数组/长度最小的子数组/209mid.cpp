class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sum = 0;
        int start = 0;
        int sublen = 0;
        for(int end=0; end<=nums.size()-1; end++){
            sum+=nums[end];
            while(sum>=target){
                sublen = end-start+1;
                sum-=nums[start++];
                if(res>sublen) res=sublen;
            }
        }
        if(res==INT32_MAX) return 0;
        return res;
    }
};