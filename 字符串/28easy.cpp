class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(needle.size()>haystack.size()) return -1;
        for(int i=0; i<=haystack.size()-needle.size(); i++){
            if(haystack.substr(i, needle.size())==needle){
                return i;
            }
        }
        return -1;
    }
};