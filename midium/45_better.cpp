#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_position=0;int edge=0;int step=0;
//        这个小于是最精髓的地方，边界到最后一个或者超过最后一个都无所谓
        for(int i=0;i<nums.size()-1;i++){
            max_position = max(max_position,i+nums[i]);
            if(i==edge){
                edge = max_position;
                step+=1;
            }
        }
        return step;
    }
};
