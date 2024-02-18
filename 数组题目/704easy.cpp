class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left <= right){
            int index = (left + right)/2;
            if(nums[index]==target){
                return index;
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