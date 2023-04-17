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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int curMin = q.front().second ;
            long long rightmost,leftmost;
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode *node = it.first;
                int index = it.second -curMin;
                if(i==0) leftmost = index;
                if(i == n-1) rightmost = index;
                if(node->left) q.push({node->left,(index*2LL)+1});
                if(node->right) q.push({node->right,(index*2LL)+2});
            }
            ans = max(ans,rightmost-leftmost+1);
        }
        return ans;
    }
};