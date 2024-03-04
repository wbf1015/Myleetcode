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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        queue<TreeNode*>q;

        if(root==nullptr) return ret;
        q.push(root);
        int size=1;

        while(!q.empty()){
            vector<int>vi;
            for(int i=1;i<=size;i++){
                TreeNode*tmp = q.front(); q.pop();
                vi.push_back(tmp->val);
                if(tmp->left!=nullptr) q.push(tmp->left);
                if(tmp->right!=nullptr) q.push(tmp->right);
            } 
            ret.push_back(vi);
            size = q.size();
        }

        return ret;
    }
};