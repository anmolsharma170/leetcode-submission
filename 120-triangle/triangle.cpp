class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),INT_MIN));
        for(int i = 0;i<triangle.size();i++){
            for(int j = 0;j<triangle[i].size();j++){
                if(i==0 && j==0) dp[i][j]=triangle[i][j];
                else if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                else if(j==i) dp[i][j]= dp[i-1][j-1]+triangle[i][j];
                else{
                    // dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j-1]+triangle[i][j+1]);
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int n=dp.size();
        for(int i = 0;i<dp.size();i++){
            for(int j = 0;j<dp[i].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int minele = INT_MAX;
        for(int j = 0;j<dp[n-1].size();j++){
            minele = min(dp[n-1][j],minele);
        }
        return minele;
    }
};