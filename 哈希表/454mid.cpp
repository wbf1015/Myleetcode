class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>fremap;
        int ret=0;
        for(auto a:nums1){
            for(auto b:nums2){
                if(fremap.count(a+b)==0){
                    fremap[a+b]=1;
                }else{
                    fremap[a+b]++;
                }
            }
        }

        for(auto c:nums3){
            for(auto d:nums4){
                if(fremap.count(0-c-d)!=0){
                    ret+=fremap[0-c-d];
                }
            }
        }
        return ret;
    }
};