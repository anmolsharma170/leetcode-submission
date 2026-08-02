class Solution {
public:
    int find(vector<int> &parent,int a){
        return parent[a]=(parent[a]==a)?a:find(parent,parent[a]);
    }
    void Union(vector<int> &parent,vector<int> &rank,int a,int b){
        a = find(parent,a);
        b = find(parent,b);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto edge: edges){
            Union(parent,rank,edge[0],edge[1]);
        }
        return find(parent,source)==find(parent,destination);
    }
};