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
    void solve(TreeNode *root,vector<int> &ans,int level,int &maxlevel){
        if(!root)return ;
        if(level>maxlevel){
            ans.push_back(root->val);
            maxlevel = level;
        }

        solve(root->right,ans,level+1,maxlevel);
        solve(root->left,ans,level+1,maxlevel);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxlevel = -1;
        solve(root,ans,0,maxlevel);
        return ans;
    }
};