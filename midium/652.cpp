//自己写的，只能打败5%的程序
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
    map<TreeNode*,string>mts;
    string getString(TreeNode* root){
        string s=std::to_string(root->val);
        if(!root->left&&!root->right){
            if(mts.find(root)!=mts.end()){
                return mts[root];
            }else{
                mts[root]=s;
                return s;
            }
        }
        if(root->left&&!root->right){
            if(mts.find(root)!=mts.end()){
                return mts[root];
            }else{
                s.append(",");
                s.append(getString(root->left));
                s.append(",");
                s.append("null");
                mts[root]=s;
                return s;
            }
        }
        if(!root->left&&root->right){
            if(mts.find(root)!=mts.end()){
                return mts[root];
            }else{
                s.append(",");
                s.append("null");
                s.append(",");
                s.append(getString(root->right));
                mts[root]=s;
                return s;
            }
        }
        if(root->left&&root->right){
            if(mts.find(root)!=mts.end()){
                return mts[root];
            }else{
                s.append(",");
                s.append(getString(root->left));
                s.append(",");
                s.append(getString(root->right));
                mts[root]=s;
                return s;
            }
        }
        return "error";
    }
    set<string>ss;
    vector<TreeNode*>vt;
    set<string>repeat;
    void help(TreeNode*root){
        string s=getString(root);
        //cout<<s<<endl;
        if(ss.count(s)==0){
            ss.insert(s);
        }else{
            if(repeat.count(s)==0){
                vt.push_back(root);
                repeat.insert(s);
            }
        }
        if(root->left){help(root->left);}
        if(root->right){help(root->right);}
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        help(root);
        return vt;
    }
};