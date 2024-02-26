class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ret(n, vector<int>(n));
        int circle=0;
        if(n%2==0){circle=n/2;}
        else{
            circle=n/2+1;
            ret[n/2][n/2]=n*n;
        }
        int count=1;
        for(int c=0;c<circle;c++){
            // 先画上横线
            for(int col=0+c; col<n-1-c;col++){
                ret[0+c][col]=count++;
            }
            // 再画右竖线
            for(int row=0+c; row<n-1-c; row++){
                ret[row][n-1-c]=count++;
            }
            // 再画下横线
            for(int col=n-c-1; col>c; col--){
                ret[n-1-c][col]=count++;
                cout<<col<<endl;
            }
            // 最后画左竖线
            for(int row=n-c-1; row>c; row--){
                ret[row][0+c]=count++;
            }
        }
        return ret;
    }
};