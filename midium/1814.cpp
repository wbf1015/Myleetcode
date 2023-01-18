class Solution {
public:
    int revInt(int i){
        int ret=0;
        while(i>0){
            ret*=10;
            ret+=i%10;
            i/=10;
        }
        return ret;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>hash;
        int ret=0;
        for(int i=0;i<nums.size();i++){
            int temp=revInt(nums[i]);
            ret=(ret+hash[nums[i]-temp])%(1000000007);
            hash[nums[i]-temp]++;
        }
        return ret;
    }
};