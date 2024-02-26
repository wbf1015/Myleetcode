class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map1;

        for(int i=0; i<nums.size(); i++){
            if(map1.count(target-nums[i])!=0){
                return {i, map1[target-nums[i]]};
            }else{
                map1[nums[i]] = i;
            }
        }

        return {};
    }
};