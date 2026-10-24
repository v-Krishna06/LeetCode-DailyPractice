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
    TreeNode* p = NULL;
    TreeNode* f = NULL;
    TreeNode* s = NULL;
    void fn(TreeNode* root){
        if(root==NULL){
            return ;
        }
        fn(root->left);
        if(p!=NULL && p->val > root->val){
            if(f==NULL){
                f = p;
            }
            s = root;
            
        }
        p = root;
        fn(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        fn(root);
        int temp = f->val;
        f->val = s->val;
        s->val = temp;
        return;
        
    }
};