class Solution {
public:
    class Myqueue{
        public:
            deque<int>que;
            // 拿到单调队列里的最大值
            int front(){
                return que.front();
            }
            void pop(int v){
                if(!que.empty()&&que.front()==v){
                    que.pop_front();
                }
            }
            void push(int v){
                while(!que.empty()&&v>que.back()){
                    que.pop_back();
                }
                que.push_back(v);
            }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int>ret;
        for(int i=0; i<k-1; i++){
            que.push(nums[i]);
        }
        for(int i=k-1;i<nums.size();i++){
            if(i==k-1){
                que.push(nums[i]);
                ret.push_back(que.front());
                continue;
            }else{
                que.pop(nums[i-k]);
                que.push(nums[i]);
                ret.push_back(que.front());
                continue;
            }
        }
        return ret;
    }
};