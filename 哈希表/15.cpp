class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        sort(nums.begin(), nums.end());

        for(int i=0; i<=nums.size()-1; i++){
            int left=i+1;
            int right=nums.size()-1;
            
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            while(left<right){
                if(nums[i]+nums[left]+nums[right]<0){
                    left++; continue;
                }
                if(nums[i]+nums[left]+nums[right]>0){
                    right--; continue;
                }
                if(nums[i]+nums[left]+nums[right]==0){
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left<right && nums[left+1]==nums[left]) left++;
                    while(left<right && nums[right-1]==nums[right]) right--;
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};