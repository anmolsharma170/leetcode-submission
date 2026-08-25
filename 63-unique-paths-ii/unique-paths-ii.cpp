class Solution {
public:
    int helper(int sr,int sc,int dr,int dc,vector<vector<int>>& dp){
        if(sr>dr || sc>dc || dp[sr][sc]==INT_MAX) return 0;
        if(sr==dr && sc==dc) return 1;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=helper(sr+1,sc,dr,dc,dp)+helper(sr,sc+1,dr,dc,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        if(arr[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) dp[i][j]==INT_MAX;
                else dp[i][j]=-1;
            }
        }
        return helper(0,0,m-1,n-1,dp);
    }
};