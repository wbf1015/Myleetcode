class Solution {
public:
    stack<char>sc;
    string removeDuplicates(string s) {
        for(auto ch: s){
            if(sc.empty()){
                sc.push(ch);
                continue;
            }
            if(sc.top()==ch){
                while(!sc.empty()&&sc.top()==ch){
                    sc.pop();
                }
                continue;
            }else{
                sc.push(ch);
                continue;
            }
        }
        string ret="";
        while(!sc.empty()){
            ret.push_back(sc.top());
            sc.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};