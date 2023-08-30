#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int map[200][200] = {0};
        int m = grid.size();
        int n = grid[0].size();
        map[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            map[i][0] = grid[i][0] + map[i-1][0];
        }
        for(int i=1;i<n;i++){
            map[0][i] = grid[0][i] + map[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                map[i][j] = min(grid[i][j]+map[i-1][j],grid[i][j]+map[i][j-1]);
            }
        }
        return map[m-1][n-1];
    }
};