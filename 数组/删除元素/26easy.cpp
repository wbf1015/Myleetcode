class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int slowpoint = 0;
        int fastpoint = 1;
        for(;fastpoint<=nums.size()-1;fastpoint++){
            if(nums[slowpoint]!=nums[fastpoint]){
                nums[++slowpoint] = nums[fastpoint];
            }
        }
        return slowpoint+1;
    }
};