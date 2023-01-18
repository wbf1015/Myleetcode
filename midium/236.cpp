/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //如果不存在就返回空指针
        if(root==nullptr){return nullptr;}
        //如果找到自己了就返回自己
        if(root==p||root==q){return root;}
        TreeNode*Left=lowestCommonAncestor(root->left,p,q);
        TreeNode*Right=lowestCommonAncestor(root->right,p,q);
        if(Left!=nullptr&&Right!=nullptr){return root;}
        if(Left!=nullptr&&Right==nullptr){return Left;}
        if(Left==nullptr&&Right!=nullptr){return Right;}
        return nullptr;
    }
};