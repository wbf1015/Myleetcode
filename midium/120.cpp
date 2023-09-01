class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> floor1;
        vector<int> floor2;
        for(int i=0;i<triangle.size();i++){
            if(i==0){
                floor1.emplace_back(triangle[i][0]);
            }else{
                for(int j=0;j<i+1;j++){
                    if(j==0){
                        floor2.emplace_back(triangle[i][j]+floor1[0]);
                        continue;
                    }
                    if(j==i){
                        floor2.emplace_back(triangle[i][j]+floor1[i-1]);
                        floor1 = floor2;
                        floor2.clear();
                        continue;
                    }
                    floor2.emplace_back(min(triangle[i][j]+floor1[j-1],triangle[i][j]+floor1[j]));
                }
            }
        }
        int ret = floor1[0];
        for(int i=0;i<floor1.size();i++){
            ret = min(ret, floor1[i]);
        }
        return ret;
    }
};