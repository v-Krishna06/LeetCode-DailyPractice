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
int n;
    TreeNode* solve(string t,int &i,int d){
        if(i>=n){
            return NULL;
        }
        int j = i;
        while(j<=n && t[j]=='-'){
            j++;
        }
        int dash = j-i;
        if(dash!=d){
            return NULL;
        }
        i+=dash;
        int num = 0;
        while(i<n && isdigit(t[i])){
            num = num*10 +(t[i]-'0');
            i++;
        }
        TreeNode* root  = new TreeNode(num);
        root->left = solve (t,i,d+1);
        root->right = solve(t,i,d+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0;
        int depth = 0;
        return solve(traversal,i,depth);
    }
};