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
    int solve(TreeNode *root,int &maxheight){
        if(!root) return 0;
        int l = solve(root->left,maxheight);
        int r = solve(root->right,maxheight);
        maxheight = max(maxheight,r+l);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxheight=0;
        if(!root) return 0;
        solve(root,maxheight);
        return maxheight;
    }
};