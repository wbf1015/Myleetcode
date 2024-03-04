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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>st;
        if(root==nullptr) return ret;
        TreeNode* cur=root;
        // cur代表现在在处理的结点，st中是待处理的结点，只有这两个都没了才能认为结束
        while(cur!=nullptr || !st.empty()){
            // 这个if的作用就是一直向左找一直找到头儿
            if(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
                continue;
            }else{
                // 当你来到这里说明st.top()所代表的结点的左子树全部处理完了，现在该处理自己了（中序）
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);
                // 自己处理完了再处理右子树
                cur = cur->right;
            }
        }
        return ret;
    }
};