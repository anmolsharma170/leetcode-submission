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
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inordervec;
        inorder(root,inordervec);
        int n = inordervec.size();
        for(auto ele: inordervec) cout<<ele<<" ";
        int i=0;
        int j = n-1;
        while(i<j){
            int sum = inordervec[i]+inordervec[j];
            if(sum==k) return true;
            else if(sum<k) i++;
            else j--;
        }
        return false;
    }
};