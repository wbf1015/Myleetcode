class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==""&&t=="") return true;
        if(s.size()!=t.size()) return false;
        unordered_map<char, int>smap;
        unordered_map<char, int>tmap;
        
        for(auto ch: s){
            if(smap.count(ch)==0){
                smap[ch]=1;
            }else{
                smap[ch]++;
            }
            
        }
        
        for(auto ch: t){
            if(tmap.count(ch)==0){
                tmap[ch]=1;
            }else{
                tmap[ch]++;
            }
        }

        if(smap.size()!=tmap.size()) return false;
        for(unordered_map<char,int>::iterator iter=smap.begin(); iter!=smap.end(); iter++){
            char ch = iter->first;
            int i = iter->second;
            if(tmap.count(ch)==0||tmap[ch]!=i){
                return false;
            }
        }
        return true;
    }
};