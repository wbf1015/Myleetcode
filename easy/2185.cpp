class Solution {
public:
    bool isContain(string a,string b){
        if(a.size()<b.size()){return false;}
        for(int i=0;i<b.size();i++){
            if(a[i]!=b[i]){return false;}
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ret=0;
        for(int i=0;i<words.size();i++){
            if(isContain(words[i],pref)){ret++;}
        }
        return ret;
    }
};