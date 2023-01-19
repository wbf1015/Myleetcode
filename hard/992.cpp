class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayMaxKDistinct(nums,k)-subarrayMaxKDistinct(nums,k-1);
    }

    int subarrayMaxKDistinct(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int>map;
        int left=0;int right=0;int ret=0;
        while(right<n){
            map[nums[right]]++;
            right++;
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0){map.erase(nums[left]);}
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};