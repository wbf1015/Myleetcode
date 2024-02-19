class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findleft(nums, target);
        if(left==-1){
            return {-1, -1};
        }
        int right = findright(nums, target);
        return {left, right};
    }
    int findleft(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int index = (left+right)/2;
            if(nums[index]==target){
                if(index==0){
                    return 0;
                }
                if(nums[index-1]!=target){
                    return index;
                }else{
                    right = index-1;
                    continue;
                }
            }
            if(nums[index]>target){
                right = index-1;
            }else{
                left = index+1;
            }
        }
        return -1;
    }
    int findright(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int index = (left+right)/2;
            if(nums[index]==target){
                if(index==nums.size()-1){
                    return index;
                }
                if(nums[index+1]!=target){
                    return index;
                }else{
                    left = index+1;
                    continue;
                }
            }
            if(nums[index]>target){
                right = index-1;
            }else{
                left = index+1;
            }
        }
        return -1;
    }
};