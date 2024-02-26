class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        vector<int>ret;

        for(auto i:nums1){
            if(map1.count(i)==0){
                map1[i]=1;
            }else{
                map1[i]++;
            }
        }

        for(auto i:nums2){
            if(map2.count(i)==0){
                map2[i]=1;
            }else{
                map2[i]++;
            }
        }

        for(unordered_map<int,int>::iterator it=map1.begin(); it!=map1.end(); it++){
            if(map2.count(it->first)==0){
                continue;
            }else{
                int count = min(it->second, map2[it->first]);
                for(int i=1; i<=count; i++){
                    ret.push_back(it->first);
                }
            }
        }

        return ret;
    }
};