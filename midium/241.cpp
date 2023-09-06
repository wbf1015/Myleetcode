#include <iostream>
#include <vector>
#include<string>

using namespace std;

//这道题确实蛮有难度的，很多技术都融合进去了
class Solution {
public:
    int ADD=-1;
    int SUB=-2;
    int MUL=-3;
    vector<int> diffWaysToCompute(string expression) {
        //先把string表达式变成一个vector的int数组
        vector<int> exp;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='+'){
                exp.push_back(ADD);
                continue;
            }
            if(expression[i]=='-'){
                exp.push_back(SUB);
                continue;
            }
            if(expression[i]=='*'){
                exp.push_back(MUL);
                continue;
            }
            // 说明这个数字是一个一位数
            if(i==expression.size()-1||expression[i+1]=='+'||expression[i+1]=='-'||expression[i+1]=='*'){
                int temp = expression[i]-'0';
                exp.push_back(temp);
                continue;
            }else{
                int temp = (expression[i]-'0')*10+(expression[++i]-'0');
                exp.push_back(temp);
                continue;
            }
        }
        // for(auto v:exp){
        //     cout<<v<<endl;
        // }
        //此时exp装着的应该就都是int类型的数据了
        //先把对角线都初始化好
        vector<int> dp[20][20];
        for(int i=exp.size()-1;i>=0;i-=2){
            dp[i][i].push_back(exp[i]);
        }
        //然后从最后一行开始一次向上来统计所有可能的结果,并且要注意跳过运算符
        for(int i=exp.size()-1;i>=0;i-=2){
            for(int j=i+2;j<exp.size();j+=2){
                //现在需要向dp[i][j]这个vector中push_back值
                int count=1;
                // 现在这个格子的内容只需要从前面向后找
                for(int k=i;k<j;k+=2){
                    vector<int>v1 = dp[i][k];
                    vector<int>v2 = dp[i+2*count++][j];
                    cout<<v1.size()<<" "<<v2.size()<<endl;
                    for(auto val1 : v1){
                        for(auto val2: v2){
                            //对于符号的判断根据目前这个格子的前一个判断
                            if(exp[k+1]==-1){
                                dp[i][j].push_back(val1+val2);
                            }
                            if(exp[k+1]==-2){
                                dp[i][j].push_back(val1-val2);
                            }
                            if(exp[k+1]==-3){
                                dp[i][j].push_back(val1*val2);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][exp.size()-1];
    }
};