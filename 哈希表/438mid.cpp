class Solution {
public:
    bool judge(unordered_map<char, int>&smap, unordered_map<char, int>&pmap){
        for(unordered_map<char,int>::iterator it=pmap.begin(); it!=pmap.end(); it++){
            if(smap.count(it->first)==0) return false;
            if(smap[it->first]!=it->second) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int>ret;
        unordered_map<char, int>pmap;
        unordered_map<char, int>smap;

        if(s.size()<p.size()){
            return ret;
        }
        
        for(auto ch:p){
            if(pmap.count(ch)==0){
                pmap[ch]=1;
            }else{
                pmap[ch]++;
            }
        }

        int slowpoint=0;
        int fastpoint=0;
        
        for(; slowpoint<=s.size()-p.size()+1;){
            for(; fastpoint<p.size(); fastpoint++){
                if(smap.count(s[slowpoint+fastpoint])==0){
                    smap[s[slowpoint+fastpoint]]=1;
                }else{
                    smap[s[slowpoint+fastpoint]]++;
                }
            }

            if(judge(smap, pmap)){
                ret.push_back(slowpoint);
                smap[s[slowpoint++]]--;
                fastpoint--;
                continue;
            }else{
                smap[s[slowpoint++]]--;
                fastpoint--;
                continue;
            }
        }
        return ret;
    }
};