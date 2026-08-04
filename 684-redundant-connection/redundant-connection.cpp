class Solution {
public:
    int find(vector<int> &parent,int a){
        return parent[a]=(parent[a]==a)?a:find(parent,parent[a]);
    }
    void Union(vector<int> &parent,vector<int> &rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n+1,0);
        for(int i=0;i<edges.size();i++){
            if(find(parent,edges[i][0])!=find(parent,edges[i][1])) Union(parent,rank,edges[i][0],edges[i][1]);
            else {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
        }
        return ans;
    }
};