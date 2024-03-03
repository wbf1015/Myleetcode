class Solution {
public:
    // 声明一个小顶堆
    class mycompare{
        public:
            bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
                return p1.second > p2.second;
            }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>imap;
        vector<int>vi(k);
        // 统计频率
        for(auto i:nums){
            if(imap.count(i)==0){
                imap[i]=1;
            }else{
                imap[i]++;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycompare> pri_que;
        for(unordered_map<int,int>::iterator it=imap.begin(); it!=imap.end(); it++){
            pri_que.push(*it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        for(int i=k-1; i>=0; i--){
            vi[i] = pri_que.top().first;
            pri_que.pop();
        }
        return vi;
    }
};