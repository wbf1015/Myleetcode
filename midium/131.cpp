#include <iostream>
#include <vector>
#include<string>

using namespace std;


// 感觉这道题目有一个非常重要的想法就是不可能没有解，至少会有一个解就是所有的字符串长度都只有1
class Solution {
public:
    bool is_reverse_str(string s){
        if(s.size()==1){
            return true;
        }
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size()==1){
            vector<string>vs;
            vs.emplace_back(s);
            ret.push_back(vs);
            return ret;
        }
        for(int i=1;i<=s.size();i++){
            string temp = s.substr(0,i);
            if(is_reverse_str(temp)){
                vector<vector<string>> sub_ret = partition(s.substr(i));
                for(int j=0;j<sub_ret.size();j++){
                    sub_ret[j].insert(sub_ret[j].begin(),temp);
                    ret.emplace_back(sub_ret[j]);
                }
                if(sub_ret.size()==0){
                    vector<string>vs;
                    vs.emplace_back(temp);
                    ret.emplace_back(vs);
                }
            }else{
                continue;
            }
        }
        return ret;
    }
};