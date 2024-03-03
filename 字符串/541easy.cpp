class Solution {
public:
    // start和end都要求是能够被切实访问的下标
    string rev_str(string s, int start, int end){
        string ret = s;
        int t = (end-start+1)/2;
        for(int i=0; i<t; i++){
            char tmp = ret[start+i];
            ret[start+i] = ret[end-i];
            ret[end-i] = tmp;
        }
        return ret;
    }
    string reverseStr(string s, int k) {
        if(s.size()<2*k){
            if(s.size()<k){
                return rev_str(s, 0, s.size()-1);
            }else{
                return rev_str(s, 0, k-1);
            }
        }
        int pointer = 2*k;
        string tmp = s;
        while(true){
            tmp = rev_str(tmp, pointer-2*k, pointer-k-1);

            if(s.size()-pointer<2*k){
                if(s.size()-pointer<k){
                    tmp = rev_str(tmp, pointer, s.size()-1);
                }else{
                    tmp = rev_str(tmp, pointer, pointer+k-1);
                }
                break;
            }else{
                pointer = pointer + 2*k;
                continue;
            }

        }
        return tmp;
    }
};