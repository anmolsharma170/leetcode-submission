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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mp;
        queue<tuple<TreeNode*,int ,int>> q;
        vector<vector<int>> ans;
        q.push({root,0,0});
        while(!q.empty()){
            auto [node,row,col] = q.front();
            mp[col][row].push(node->val);
            q.pop();
            if(node->left) q.push({node->left,row+1,col-1});
            if(node->right) q.push({node->right,row+1,col+1});
        }
        for(auto p:mp){
            vector<int> temp;
            for(auto q:p.second){
                auto pq = q.second;
                while(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            ans.push_back(temp);
            // for(auto )
        }
        return ans;

    }
};