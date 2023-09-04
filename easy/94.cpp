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
    vector<int> inorderTraversal(TreeNode* root) {
        // 必须先判断这个东西有没有
        if(!root){
            return {};
        }
        if(root->left==NULL &&root->right==NULL){
            vector<int>vi;
            vi.emplace_back(root->val);
            return vi;
        }
        vector<int> left_node = inorderTraversal(root->left);
        vector<int> right_node = inorderTraversal(root->right);
        left_node.emplace_back(root->val);
        for(int i=0;i<right_node.size();i++){
            left_node.emplace_back(right_node[i]);
        }
        return left_node;
    }
};