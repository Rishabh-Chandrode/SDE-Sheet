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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,int>> q;
        int level=-1;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            level++;
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode *node = it.first;
                int hd = it.second;
                m[hd][level].insert(node->val);
                if(node->left) q.push({node->left,hd-1});
                if(node->right) q.push({node->right,hd+1});

            }
        }

        for(auto it1:m){
            vector<int> temp;
            for(auto it2:it1.second){
                temp.insert(temp.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};