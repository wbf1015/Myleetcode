class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int left = 0;
        int right = x/2;
        while(left<=right){
            int index = (left+right)/2;
            if((long long)index*index==(long long)x){
                return index;
            }
            if((long long)index*index < x){
                if((long long)(index+1)*(index+1)>x){
                    return index;
                }else{
                    left = index+1;
                }
            }
            if((long long)index*index > x){
                if((long long)(index-1)*(index-1)<x){
                    return index-1;
                }else{
                    right = index-1;
                }
            }
        }
        return 0;
    }
};