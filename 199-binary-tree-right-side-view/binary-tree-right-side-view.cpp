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
    vector<int> rightSideView(TreeNode* root) {
        if( root==nullptr) return {};
        vector<int> rightview;
        queue<TreeNode*> q;
        TreeNode* curr = root;
        TreeNode* prev = root;
        q.push(curr);
        q.push(nullptr);
        while(!q.empty()){
            prev = curr;
            curr = q.front();
            q.pop();
            while(curr!=nullptr){
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
                prev = curr;
                curr = q.front();
                q.pop();
            }
            rightview.push_back(prev->val);
            if(!q.empty())q.push(nullptr);
        }
        return rightview;
    }
};