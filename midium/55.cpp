#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>vi;
        vi.resize(nums.size(),1);
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                vi[i]== true;
            }else{
                bool flag = false;
                for(int j=1;j<=nums[i]&&i+j<=nums.size()-1;j++){
                    if(vi[i+j]){
                        flag=true;
                        break;
                    }
                }
                vi[i] = flag;
            }
        }
        return vi[0];
    }
};
