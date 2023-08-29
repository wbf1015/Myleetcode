class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos=0;
        int can_go=0;
        for(int i=0;i<nums.size()-1&&i<=can_go;i++){
            can_go = max(can_go,i+nums[i]);
            max_pos = max(max_pos,i+nums[i]);
        }
        if(max_pos>=nums.size()-1){
            return true;
        }
        return false;
    }
};