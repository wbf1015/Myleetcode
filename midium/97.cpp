#include <iostream>
#include <vector>
#include<string>

using namespace std;



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if(n+m!=t){
            return false;
        }
        int dp[101][101]={0};
        dp[0][0] = 1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i>0){
                    if(dp[i-1][j]==1&&s1[i-1]==s3[i+j-1]){
                        dp[i][j]=1;
                    }
                }
                if(j>0){
                    if(dp[i][j-1]==1&&s2[j-1]==s3[i+j-1]){
                        dp[i][j]=1;
                    }
                }
            }
        }
        if(dp[n][m]==1){
            return true;
        }else{
            return false;
        }
    }
};