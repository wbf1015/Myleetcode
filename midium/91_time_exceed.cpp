class Solution {
public:
    bool legal_str(string s){
        if(s.size()==1){
            if(s[0]=='0'){
                return false;
            }
            return true;
        }
        if(s.size()==2){
            if(s[0]=='0'){
                return false;
            }
            if(s[0]=='2'&&s[1]>='7'){
                return false;
            }
            if(s[0]>='3'){
                return false;
            }
            return true;
        }
        return false;
    }
    int core_decoding(string s1,string s2){
        if(legal_str(s1)){
            if(s2.size()==0){
                return 1;
            }
            if(s2.size()==1){
                if(legal_str(string(1,s2[0]))){
                    return 1;
                }else{
                    return 0;
                }
            }
            if(s2.size()==2){
                int count = 0;
                if(legal_str(string(1,s2[0]))&& legal_str(string(1,s2[1]))){
                    count++;
                }
                if(legal_str(s2)){
                    count++;
                }
                return count;
            }
            return core_decoding(s2.substr(0,1),s2.substr(1)) + core_decoding(s2.substr(0,2),s2.substr(2));
        }else{
            return 0;
        }
    }
    int numDecodings(string s) {
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            if(legal_str(s)){
                return 1;
            }else{
                return 0;
            }
        }
        return core_decoding(s.substr(0,1), s.substr(1)) + core_decoding(s.substr(0,2),s.substr(2));
    }
};