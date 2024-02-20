class Solution {
public:
    unordered_map<char, int>target, now;

    void init_map(string t){
        for(auto ch : t){
            if(target.find(ch)!=target.end()){
                target[ch]++;
            }else{
                target[ch]=1;
            }
        }
    }

    bool check(){
        for(auto&[k,v]:target){
            if(now[k]<target[k]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        init_map(t);
        int start=0, end=0, res_len=INT32_MAX;
        int res_start=-1;
        for(; end<=s.size()-1; end++){
            if(target.find(s[end])!=target.end()){
                if(now.find(s[end])!=now.end()){
                    now[s[end]]++;
                }else{
                    now[s[end]] = 1;
                }
            }
            while(check()){
                int tmp_len = end-start+1;
                if(res_len>tmp_len){
                    res_len=tmp_len;
                    res_start=start;
                }
                if(target.find(s[start])!=target.end()){
                    now[s[start]]--;
                }
                start++;
            }
        }
        if(res_start==-1) return "";
        return s.substr(res_start, res_len);
    }
};