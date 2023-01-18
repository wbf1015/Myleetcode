class Solution {
public:
    void init(vector<int>&vi,int n){
        for(int i=0;i<n;i++){
            vi.push_back(i);
        }
    }
    void change(vector<int>&vi){
        vector<int>temp(vi);
        int n = vi.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                vi[i]=temp[i/2];
            }else{
                vi[i]=temp[n/2+(i-1)/2];
            }
        }
    }
    bool equal(vector<int>&v1,vector<int>v2){
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){return false;}
        }
        return true;
    }
    int reinitializePermutation(int n) {
        vector<int>perm;
        init(perm,n);
        vector<int>vi;
        init(vi,n);
        int ret=0;
        do{
            change(vi);
            ret++;
        }while(!equal(vi,perm));
        return ret;
    }
};