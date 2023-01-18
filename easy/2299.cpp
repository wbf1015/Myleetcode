class Solution {
public:
    bool Small_Eng=false;
    bool Big_Eng=false;
    bool number=false;
    bool Special=false;
    set<char>sc;
    bool strongPasswordCheckerII(string password) {
        string s=password;
        if(password.size()<8){return false;}
        sc.insert('!');
        sc.insert('@');
        sc.insert('#');
        sc.insert('$');
        sc.insert('%');
        sc.insert('^');
        sc.insert('&');
        sc.insert('*');
        sc.insert('(');
        sc.insert(')');
        sc.insert('-');
        sc.insert('+');
        for(int i=0;i<password.size();i++){
            if(s[i]>=97&&s[i]<=122&&!Small_Eng){Small_Eng=true;}
            if(s[i]>=65&&s[i]<=90&&!Big_Eng){Big_Eng=true;}
            if(s[i]>=48&&s[i]<=57&&!number){number=true;}
            if(sc.find(s[i])!=sc.end()&&!Special){Special=true;}
            if(i!=0){
                if(s[i]==s[i-1]){return false;}
            }
        }
        if(Small_Eng&&Big_Eng&&number&&Special){return true;}
        return false;
    }
};