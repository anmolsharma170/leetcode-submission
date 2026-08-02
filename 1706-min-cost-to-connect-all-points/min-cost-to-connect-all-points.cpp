class Solution {
public:
    int find(vector<int> &parent,int a){
        return parent[a]=(parent[a]==a)? a:find(parent,parent[a]);
    }
    void Union(vector<int> &parent,vector<int> &rank, int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(a==b) return;
        if(rank[a]>rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    int kruskals(vector<vector<int>>& edges,int e,int v){
        sort(edges.begin(),edges.end());
        long long ans = 0;
        vector<int> parent(v+1);
        for(int i = 0;i<=v;i++){
            parent[i]=i;
        }
        vector<int> rank(v+1,1);
        for(auto& edge: edges){
            int wt = edge[0];
            int src = edge[1];
            int des = edge[2];
            int srcpar = find(parent,src);
            int despar = find(parent,des);
            if(srcpar!=despar){
                Union(parent,rank,srcpar,despar);
                ans+=wt;
            }
        }
        return ans;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]); 
                edges.push_back({wt,i,j});
            }
        }
        int e=edges.size();
        int v = e+1;
        int ans =  kruskals(edges,e,v);
        return ans;
    }
};