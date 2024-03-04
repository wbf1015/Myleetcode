/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preTra(TreeNode* root){
        vector<int>ret;
        if(root==nullptr){
            return ret;
        }
        // 前序遍历先压自己
        ret.push_back(root->val);
        // 然后找左子树
        vector<int>tmp = preTra(root->left);
        for(auto v:tmp){
            ret.push_back(v);
        }
        // 然后找右子树
        tmp = preTra(root->right);
        for(auto v:tmp){
            ret.push_back(v);
        }
        return ret;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return preTra(root);
    }
};