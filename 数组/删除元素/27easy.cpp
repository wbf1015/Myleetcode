class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){
            return 0;
        }
        int fastnode = 0;
        int slownode = 0;
        for(;fastnode<=nums.size()-1;fastnode++){
            if(nums[fastnode]!=val){
                nums[slownode++] = nums[fastnode];
            }
        }
        return slownode;
    }
};