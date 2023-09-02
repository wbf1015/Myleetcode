class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        bool count_flag = false;
        int best_count = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(forts[i]==-1){
                // 如果正在行军，那就可以停下来了
                if(count_flag){
                    count_flag=false;
                    best_count = max(best_count,count);
                    count = 0;
                }
            }
            if(forts[i]==0){
                //正在行军，那么就加上一个摧毁的
                if(count_flag){
                    count++;
                }
            }
            if(forts[i]==1){
                //不管在什么状态，都应该转换为行军
                if(count_flag){
                    count=0;
                }else{
                    count=0;
                    count_flag=true;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(forts[i]==-1){
                // 如果正在行军，那就可以停下来了
                if(count_flag){
                    count_flag=false;
                    best_count = max(best_count,count);
                    count = 0;
                }
            }
            if(forts[i]==0){
                if(count_flag){
                    count++;
                }
            }
            if(forts[i]==1){
                if(count_flag){
                    count=0;
                }else{
                    count=0;
                    count_flag=true;
                }
            }
        }
        return best_count;
    }
};