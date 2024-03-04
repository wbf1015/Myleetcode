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
    void getlevel(TreeNode* node, vector<vector<int>>&ret, int depth){
        if(node==nullptr) return;

        if(ret.size()<depth){
            ret.push_back(vector<int>());
        }
        ret[depth-1].push_back(node->val);

        if(node->left!=nullptr) getlevel(node->left, ret, depth+1);
        if(node->right!=nullptr) getlevel(node->right, ret, depth+1);

        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        getlevel(root, ret, 1);
        return ret;
    }
};