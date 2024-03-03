class Solution {
public:
    void reverseString(vector<char>& s) {
        int t = s.size()/2;
        for(int i=0;i<t;i++){
            char tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }
    }
};