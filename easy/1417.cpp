class Solution {
public:
    string s1="";
    string s2="";
    string reformat(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>=97&&s[i]<=122){
                s1.push_back(s[i]);
            }
            else{
                s2.push_back(s[i]);
            }
        }
        cout<<s1<<endl<<s2<<endl;
        int k=s1.size()-s2.size();
        if(k>1||k<-1){cout<<"here"<<endl;return "";}
        else{
            string ret="";
            if(s1.size()<s2.size()){
                int i=0;
                for(;i<s1.size();i++){
                    ret.push_back(s2[i]);
                    ret.push_back(s1[i]);
                }
                ret.push_back(s2[i]);
                return ret;
            }
            if(s2.size()<s1.size()){
                int i=0;
                for(;i<s2.size();i++){
                    ret.push_back(s1[i]);
                    ret.push_back(s2[i]);
                }
                ret.push_back(s1[i]);
                return ret;
            }
            if(s1.size()==s2.size()){
                int i=0;
                for(;i<s1.size();i++){
                    ret.push_back(s1[i]);
                    ret.push_back(s2[i]);
                }
                return ret;
            }
        }
        return "";
    }
};