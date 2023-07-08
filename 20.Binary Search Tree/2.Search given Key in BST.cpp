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

class BSTIterator{
    private:
        stack<TreeNode*> s;
        bool is_reverse;
        void push_all(TreeNode *root){
            TreeNode *curr = root;
            while(curr){
                s.push(curr);
                if(is_reverse){
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
        }
    public:
        BSTIterator(TreeNode *root,bool _isreverse){
            is_reverse = _isreverse;
            push_all(root);
        }

        TreeNode* next(){
            TreeNode *curr = s.top();
            s.pop();
            if(is_reverse){
                push_all(curr->left);
            }else{
                push_all(curr->right);
            }

            return curr;
        }

        bool has_next(){
            return (!s.empty());
        }

       
};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator i(root,false);
        BSTIterator j(root,true);

        int l  = i.next()->val;
        int r = j.next()->val;
        while(l<r){
            if(l+r ==k ) return true;

            if(l+r < k ){
                if(i.has_next()) l = i.next()->val;
                else return false;
            }else{
                if(j.has_next()) r = j.next()->val;
                else return false;
            }
        }
        return false;
    }
};