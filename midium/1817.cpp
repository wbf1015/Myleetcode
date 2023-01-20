class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>>map;
        for(int i=0;i<logs.size();i++){
            if(map[logs[i][0]].count(logs[i][1])==0){
                map[logs[i][0]].insert(logs[i][1]);
            }
        }
        std::map<int,int>m;
        int max=0;
        for(auto it:map){
            int n=it.second.size();
            m[n]++;
            if(max<n){max=n;}
        }
        cout<<max<<endl;
        vector<int>vi(k);
        for(auto it:m){
            if(it.first>k){continue;}
            vi[it.first-1]=it.second;
        }
        return vi;
    }
};