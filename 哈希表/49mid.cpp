class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ret; // 用来返回的
        unordered_map<string, int>strmap; //{排序之后的字符串: 对应的在ret中的index}
        int index = 0; //现在的下标
        string tmp = ""; //现在在处理的字符串
        for(auto str:strs){
            tmp=str;
            sort(tmp.begin(), tmp.end());
            if(strmap.count(tmp)!=0){
                ret[strmap[tmp]].push_back(str);
            }else{
                ret.push_back(vector<string>(1, str));
                strmap[tmp]=index++;
            }
        }
        return ret;
    }
};