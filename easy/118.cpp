#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vi;
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            if(i==1){
                temp.push_back(1);
                vi.push_back(temp);
                continue;
            }else{
                vector<int>last = vi[i-2];
                temp.push_back(1);
                for(int j=2;j<i;j++){
                    temp.push_back(last[j-2]+last[j-1]);
                }
                temp.push_back(1);
                vi.push_back(temp);
            }
        }
        return vi;
    }
};
