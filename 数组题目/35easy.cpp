class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int index = (left+right)/2;
            if(nums[index]==target){
                return index;
            }
            if(nums[index]>target){
                right = index-1;
                if(left>right){
                    return index;
                }
            }else{
                left = index+1;
                if(left>right){
                    return index+1;
                }
            }
        }
        return 0;
    }
};