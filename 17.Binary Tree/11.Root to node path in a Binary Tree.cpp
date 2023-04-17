/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void util(TreeNode* root,int &x,vector<int> &ans,bool &found){
    if(!root) return ;
    
    if(root->val == x){
        found = true;
        ans.insert(ans.begin(),root->val);
        return;
    }
    util(root->left,x,ans,found);
    if(found){
        ans.insert(ans.begin(),root->val);
        return;
    }
    util(root->right,x,ans,found);
    if(found){
        ans.insert(ans.begin(),root->val);
        return;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool found = false;
    util(A,B,ans,found);
    return ans;
}