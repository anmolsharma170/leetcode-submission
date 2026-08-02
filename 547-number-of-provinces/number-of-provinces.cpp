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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    Union(parent,rank,i,j);
                }
            }
        }
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            vis.insert(find(parent,i));
        }
        return vis.size();
    }
};