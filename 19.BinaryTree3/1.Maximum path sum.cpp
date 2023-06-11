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
    int solve(TreeNode *root,int &ans){
        if(!root) return 0;
        int l = max(0,solve(root->left,ans));
        int r = max(0,solve(root->right,ans));
        int val = root->val;
        ans = max(ans,l+r+val);
        return (max(l,r)+val);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        if(!root) return ans;
        solve(root,ans);
        return ans;

    }
};