class Solution {
public:
    bool ismid=false;
    int ans=0;
    int countAsterisks(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                if(ismid==true){ismid=false;}
                else{ismid=true;}
                continue;
            }
            if(s[i]=='*'){
                if(!ismid){ans++;}
            }
        }
        return ans;
    }
};