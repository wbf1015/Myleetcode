class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        unordered_set<int>map1;
        unordered_set<int>map2;
        for(auto i:nums1){
            map1.insert(i);
        }
        for(auto i:nums2){
            map2.insert(i);
        }
        for(unordered_set<int>::iterator it=map1.begin(); it!=map1.end(); it++){
            if(map2.find(*it)!=map2.end()){
                ret.push_back(*it);
            }
        }
        return ret;
    }
};