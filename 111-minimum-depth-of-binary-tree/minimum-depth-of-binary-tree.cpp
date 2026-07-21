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
    int nooflevels(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        if(!root->left)return 1+nooflevels(root->right);
        if(!root->right) return 1+nooflevels(root->left);
        
        
        else return 1+min(nooflevels(root->left),nooflevels(root->right));
    }
    int minDepth(TreeNode* root) {
        return nooflevels(root);
    }
};