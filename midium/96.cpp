class Solution {
public:
    int numTrees(int n) {
        int record[20] = {0};
        record[0]=1;
        record[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i-1;j++){
                record[i] += record[j]*record[i-j-1];
            }
        }
        return record[n];
    }
};