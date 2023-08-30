#include <iostream>
#include <vector>
#include<string>

using namespace std;

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
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        if(s.size()==1){
            if(legal_str(s)){
                return 1;
            }
            return 0;
        }
        if(s.size()==2){
            int count = 0;
            if(legal_str(string(1,s[0]))&& legal_str(string(1,s[1]))){
                count++;
            }
            if(legal_str(s)){
                count++;
            }
            return count;
        }
        vector<int>vi;
        vi.push_back(1);
        for(int i=1;i<s.size();i++){
            int temp = 0;
            if(legal_str(s.substr(i,1))){
                temp+=vi[i-1];
            }
            if(legal_str(s.substr(i-1,2))){
                if(i>=2){
                    temp+=vi[i-2];
                }
                else{
                    temp+=1;
                }
            }
            vi.push_back(temp);
        }
        return vi[vi.size()-1];
    }
};