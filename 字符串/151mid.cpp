class Solution {
public:
    string delspace(string s){
        bool findfirst=false;
        int first_voc=0;
        int last_voc=0;
        string ret = "";
        for(int i=0; i<s.size(); i++){
            if(findfirst){
                if(s[i]!=' '){
                    ret.push_back(s[i]);
                }else{
                    if(s[i+1]==' '||s[i+1]=='\0'){
                        continue;
                    }else{
                        ret.push_back(s[i]);
                    }
                }
            }else{
                if(s[i]!=' '){
                    findfirst=true;
                    ret.push_back(s[i]);
                }else{
                    continue;
                }
            }
        }
        return ret;
    }

    string revstr(string s){
        string ret = s;
        int t = s.size()/2;
        for(int i=0; i<t; i++){
            char tmp = ret[i];
            ret[i] = ret[s.size()-1-i];
            ret[s.size()-1-i] = tmp;
        }
        return ret;
    }

    // start和end必须都可以被访问，并且不能是空格
    string revword(string s, int start, int end){
        string ret=s;
        int t = (end-start+1)/2;
        for(int i=0; i<t; i++){
            char tmp = ret[start+i];
            ret[start+i] = ret[end-i];
            ret[end-i] = tmp;
        }
        return ret;
    }

    string reverseWords(string s) {
        string ret = delspace(s);
        cout<<ret<<endl;
        ret = revstr(ret);
        int slowpoint=0;
        int fastpoint=0;
        for(; fastpoint<=ret.size()-1; fastpoint++){
            if(fastpoint==ret.size()-1){
                ret=revword(ret, slowpoint, fastpoint);
                break;
            }
            if(ret[fastpoint]==' '){
                ret=revword(ret, slowpoint, fastpoint-1);
                slowpoint = fastpoint+1;
            }
        }
        return ret;
    }
};