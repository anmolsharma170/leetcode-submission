class Solution {
public:
    vector<vector<int>> res;
    void allpath(int src,vector<vector<int>>& graph,vector<int> &v){
        v.push_back(src);
        if(src==graph.size()-1){
            res.push_back(v);
        }
        for(auto neigh:graph[src]) allpath(neigh,graph,v);
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        allpath(0,graph,v);
        return res;
    }
};