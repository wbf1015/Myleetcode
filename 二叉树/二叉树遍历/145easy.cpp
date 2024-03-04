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
    vector<int> postTra(TreeNode* root){
        vector<int>ret;
        if(root==nullptr) return ret;
        if(root->left!=nullptr){
            vector<int>tmp = postTra(root->left);
            for(auto v:tmp){
                ret.push_back(v);
            }
        }
        if(root->right!=nullptr){
            vector<int>tmp = postTra(root->right);
            for(auto v:tmp){
                ret.push_back(v);
            }
        }
        // 最后push自己
        ret.push_back(root->val);
        return ret;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        return postTra(root);
    }
};