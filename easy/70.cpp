class Solution {
public:
    map<int,int>m;
    int climbStairs(int n) {
        if(n==1){return 1;}
        if(n==2){return 2;}
        if(m.find(n)==m.end()){
            int temp=0;
            temp = climbStairs(n-1)+climbStairs(n-2);
            m[n]=temp;
            return temp;
        }else{
            return m[n];
        }
    }
};