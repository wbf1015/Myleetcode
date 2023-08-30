#include <iostream>
#include <vector>
#include<string>

using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end){
        if(start>end){
            return {nullptr};
        }
        vector<TreeNode*>vt;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftNode = generateTrees(start,i-1);
            vector<TreeNode*> rightNode = generateTrees(i+1, end);
            for(auto& leftTree : leftNode){
                for(auto& rightTree:rightNode){
                    TreeNode* currNode =  new TreeNode(i, leftTree, rightTree);
                    vt.emplace_back(currNode);
                }
            }
        }
        return vt;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }else{
            return generateTrees(1, n);
        }
    }
};