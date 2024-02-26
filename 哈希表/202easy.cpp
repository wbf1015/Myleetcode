class Solution {
public:
    int nextit(int i){
        int sum=0;
        while(i){
            int tmp=i%10;
            sum+=tmp*tmp;
            i=i/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        int nownum = n;
        while(true){
            if(s.find(nownum)!=s.end()){
                return false;
            }
            if(nownum==1){
                return true;
            }
            s.insert(nownum);
            nownum=nextit(nownum);
        }
        return true;
    }
};