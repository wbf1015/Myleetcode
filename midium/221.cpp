class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[301][301]={0};
        int max_lengths = 0;
        //我们考虑的是这个点作为正方形的右下角
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0||j==0){
                    dp[i][j]=1;
                    max_lengths = max(max_lengths,dp[i][j]);
                    continue;
                }
                dp[i][j] = min(dp[i-1][j],(min(dp[i][j-1],dp[i-1][j-1])))+1;
                max_lengths = max(max_lengths,dp[i][j]);
            }
        }
        return max_lengths*max_lengths;
    }
};