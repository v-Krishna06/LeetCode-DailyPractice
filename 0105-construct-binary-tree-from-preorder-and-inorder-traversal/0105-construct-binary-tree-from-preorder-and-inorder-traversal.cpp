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
    int search(vector<int>& inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int &i, int l,int r) {
        if(l>r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        
        int inIdx = search(inorder,l,r,preorder[i]);
        i++;
        root->left = f(preorder,inorder,i,l,inIdx-1);
        root->right = f(preorder,inorder,i,inIdx+1,r);
        return  root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pi = 0;
        return f(preorder,inorder,pi,0,inorder.size()-1);
    }
};