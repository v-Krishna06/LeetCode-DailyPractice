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
    vector<TreeNode*> s(int st,int end){
        if(st>end){
            return {NULL};
        }
        if(st==end){
            TreeNode* root = new TreeNode(st);
            return {root};
        }
        vector<TreeNode*> res;
        for(int i = st;i<=end;i++){
            vector<TreeNode*> l = s(st,i-1);
            vector<TreeNode*> r = s(i+1,end);
            for(TreeNode* lr : l){
                for(TreeNode* rr: r){
                    TreeNode* root = new TreeNode(i);
                    root->left = lr;
                    root->right = rr;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return s(1,n);
    }
};