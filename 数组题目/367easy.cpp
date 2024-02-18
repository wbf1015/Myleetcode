class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1|num==4) return true;
        if(num==2|num==3) return false;
        int l = 0;
        int r = num/2;
        while(l<=r){
            int index = (l+r)/2;
            if((long long)index*index==num){
                return true;
            }
            if((long long)index*index>num){
                r = index-1;
            }else{
                l = index+1;
            }
        }
        return false;
    }
};