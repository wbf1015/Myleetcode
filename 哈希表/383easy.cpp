class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>ranmap;
        unordered_map<char, int>magmap;

        for(auto ch:ransomNote){
            if(ranmap.count(ch)==0){
                ranmap[ch]=1;
            }else{
                ranmap[ch]++;
            }
        }

        for(auto ch:magazine){
            if(magmap.count(ch)==0){
                magmap[ch]=1;
            }else{
                magmap[ch]++;
            }
        }

        for(unordered_map<char, int>::iterator it=ranmap.begin(); it!=ranmap.end(); it++){
            if(magmap.count(it->first)==0){
                return false;
            }
            if(magmap[it->first] < it->second){
                return false;
            }
        }

        return true;
    }
};