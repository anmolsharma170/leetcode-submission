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
    int cal(TreeNode* root,int &noOfNodes){
        if(root==NULL) return 0;
        noOfNodes++;
        return root->val+cal(root->left,noOfNodes)+cal(root->right,noOfNodes);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int count = 0;
        count+=averageOfSubtree(root->left);
        int noOfNodes = 0;
        int sum = cal(root,noOfNodes);
        int avg = sum/noOfNodes;
        if(root->val==avg) count++;
        count+=averageOfSubtree(root->right);
        return count;
    }
};