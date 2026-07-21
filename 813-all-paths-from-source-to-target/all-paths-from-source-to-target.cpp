class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int curr,vector<vector<int>>& graph,vector<int> &v){
        v.push_back(curr);
        if(curr==graph.size()-1){
            ans.push_back(v);
        }
        {
            for(int neigh: graph[curr]){
                dfs(neigh,graph,v);
            }
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        dfs(0,graph,v);
        return ans;
    }
};