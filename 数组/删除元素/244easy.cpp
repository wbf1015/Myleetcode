class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string rels = getstr(s);
        string relt = getstr(t);
        return rels==relt;
    }
    string getstr(string s){
        int slowpoint = 0;
        int fastpoint = 0;
        for(; fastpoint<=s.size()-1; fastpoint++){
            if(s[fastpoint]=='#'){
                if(slowpoint==0){
                    continue;
                }else{
                    slowpoint--;
                }
            }else{
                s[slowpoint++]=s[fastpoint];
            }
        }
        return s.substr(0,slowpoint);
    }
};