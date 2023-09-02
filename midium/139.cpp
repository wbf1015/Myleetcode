// 写到破防的一道题，教训就是一定要画表，要不很折磨
class Solution {
public:
    bool has_str(vector<string>& wordDict, string str){
        for(int i=0;i<wordDict.size();i++){
            if(wordDict[i]==str){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301]={false};
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            string temp = s.substr(0,i);
            for(int j=temp.size();j>0;j--){
                if(has_str(wordDict, temp.substr(i-j))&&dp[i-j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};