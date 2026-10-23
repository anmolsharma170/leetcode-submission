class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rowmp1;
        unordered_map<int,int> colmp2;
        unordered_map<int,int> posDiamp3;
        unordered_map<int,int> negDiamp4;
        unordered_map<int,int> mp5;
        vector<vector<int>> dirs = {{0,1},{0,-1},{-1,-1},{-1,0},{-1,1},{1,0},{1,1},{0,0},{1,-1}};
        vector<int> ans(queries.size());
        for(auto lamp:lamps){
            long long x = lamp[0];
            long long y = lamp[1];
            rowmp1[x]++;
            colmp2[y]++;
            posDiamp3[x+y]++;
            negDiamp4[x-y]++;
            mp5[n*x+y]++;
        }
        for(int i=0;i<queries.size();i++){
            long long x = queries[i][0];
            long long y = queries[i][1];
            ans[i]=(rowmp1[x]>0 || colmp2[y]>0 || posDiamp3[x+y]>0 || negDiamp4[x-y]>0)? 1:0;

            // turning off lamps
            for(auto dir: dirs){
                long long x1 = x+dir[0];
                long long y1 = y+dir[1];
                if(x1>=0 && y1>=0 && x1<n && y1<n && mp5.count(n*x1+y1)){
                    int times = mp5[n*x1+y1];
                    rowmp1[x1]-=times;
                    colmp2[y1]-=times;
                    posDiamp3[x1+y1]-=times;
                    negDiamp4[x1-y1]-=times;
                    mp5.erase(n*x1+y1);
                }
            }
        }

        return ans;
    }
};