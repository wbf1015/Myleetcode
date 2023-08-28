#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>step;
    int jump(vector<int>& nums) {
        step.resize(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                step[i]=0;
            }else{
                int min_step = nums.size()+1;
                for(int j=1;j<=nums[i];j++){
                    if(i+j>nums.size()-1){
                        break;
                    }
                    if(1+step[i+j]<min_step){
                        min_step = 1+step[i+j];
                    }
                }
                step[i] = min_step;
            }
        }
        return step[0];
    }
};
