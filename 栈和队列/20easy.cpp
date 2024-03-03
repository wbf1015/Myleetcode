class Solution {
public:
    stack<char>sc;
    bool isValid(string s) {
        for(auto ch:s){
            if(ch=='(' || ch=='[' || ch=='{'){
                sc.push(ch);
            }else{
                if(sc.empty()){
                    return false;
                }
                if(ch==')'&&sc.top()=='('){
                    sc.pop();
                    continue;
                }
                if(ch==']'&&sc.top()=='['){
                    sc.pop();
                    continue;
                }
                if(ch=='}'&&sc.top()=='{'){
                    sc.pop();
                    continue;
                }
                return false;
            }
        }
        return sc.empty();
    }
};