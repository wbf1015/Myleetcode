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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>st;
        if(root==nullptr) return ret;
        st.push(root);

        while(!st.empty()){
            TreeNode* tmp = st.top();
            ret.push_back(tmp->val);
            st.pop();
            if(tmp->right!=nullptr) st.push(tmp->right);
            if(tmp->left!=nullptr) st.push(tmp->left);
        }
        return ret;
    }
};