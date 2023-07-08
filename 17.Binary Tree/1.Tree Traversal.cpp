// Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        while(root!=NULL){
            if(root->left){
                TreeNode *prev = root->left;
                while(prev->right && prev->right != root) prev = prev->right;
                if(prev->right==NULL){
                    prev->right = root;
                    root = root->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};


// Preorder Traversal


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        while(root!=NULL){
            
            if(root->left){
                TreeNode *prev = root->left;
                
                while(prev->right && prev->right!=root){
                    
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    ans.push_back(root->val);
                    prev->right = root;
                    root = root->left;
                }else{
                    prev->right = NULL;
                    root = root->right;
                }
            }else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};


//Post order Traversal

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        while(root!=NULL){
            if(root->right){
                TreeNode *prev = root->right;
                while(prev->left && prev->left!=root){
                    prev = prev->left;
                }
                if(prev->left == NULL){
                    ans.insert(ans.begin(),root->val);
                    prev->left = root;
                    root = root->right;
                }else{
                    prev->left = NULL;
                    root = root->left;
                }
            }else{
                ans.insert(ans.begin(),root->val);
                root =root->left;
            }
        }
        return ans;
    }
}; 