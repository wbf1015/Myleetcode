#include <iostream>
#include <vector>
#include<string>

using namespace std;



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if(s1[0]!=s3[0]&&s2[0]!=s3[0]){
            return false;
        }
        if (s3.size() == 0) {
            return true;
        }
        if (s1.size() == 0) {
            if (s2[0] != s3[0]) {
                return false;
            } else {
                return isInterleave(s1, s2.substr(1), s3.substr(1));
            }
        }
        if (s2.size() == 0) {
            if (s1[0] != s3[0]) {
                return false;
            } else {
                return isInterleave(s1.substr(1), s2, s3.substr(1));
            }
        }
        bool flag = false;
        if (s1[0] == s3[0]) {
            if (isInterleave(s1.substr(1), s2, s3.substr(1))) {
                flag = true;
            }
        }
        if (flag) {
            return true;
        }
        if (s2[0] == s3[0]) {
            return isInterleave(s1, s2.substr(1), s3.substr(1));
        }
        return false;
    }
};