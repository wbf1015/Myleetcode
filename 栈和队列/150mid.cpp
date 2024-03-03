class Solution {
public:
    stack<int>ss;
    int evalRPN(vector<string>& tokens) {
        for(auto s: tokens){
            if(s!="+"&&s!="-"&&s!="*"&&s!="/"){
                ss.push(stoi(s));
                continue;
            }
            if(s=="+"){
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(a+b);
                continue;
            }
            if(s=="-"){
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(b-a);
                continue;
            }
            if(s=="*"){
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(a*b);
                continue;
            }
            if(s=="/"){
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                int tmp = b/a;
                ss.push(tmp);
                continue;
            }
        }
        return ss.top();
    }
};