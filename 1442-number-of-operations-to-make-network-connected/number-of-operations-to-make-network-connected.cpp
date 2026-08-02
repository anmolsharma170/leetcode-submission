class Solution {
public:
    int find(vector<int> &parent,int a){
        return parent[a]=(parent[a]==a)?a:find(parent,parent[a]);
    }
    void Union(vector<int> &parent, vector<int> &rank,int a,int b){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto edge: connections){
            if(find(parent,edge[0])==find(parent,edge[1])) extra++;
            else Union(parent,rank,edge[0],edge[1]);
        }
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            vis.insert(find(parent,i));
        }
        if(vis.size()-1<=extra) return vis.size()-1;
        return -1;
    }
};