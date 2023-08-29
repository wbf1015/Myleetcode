class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int map[100][100] = {0};
        for(int i=0;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0]==1){
                break;
            }
            map[i][0] = 1;
        }
        for(int i=0;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i]==1){
                break;
            }
            map[0][i]=1;
        }
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==1){
                    map[i][j]=0;
                }else{
                    map[i][j] = map[i-1][j]+map[i][j-1];
                }
            }
        }
        return map[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};