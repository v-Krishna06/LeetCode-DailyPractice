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
    void f(TreeNode* root){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL){
            f(root->left);
        }
        TreeNode* h = root;
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = NULL;
        while(h->right != NULL){
            h = h->right;
        }
        h->right = r;
        if(root->right!=NULL){
            f(root->right);
        }
    }
    void flatten(TreeNode* root) {
        f(root);
        
    }
};