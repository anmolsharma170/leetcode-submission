class Solution {
public:
    int calculate(int n,vector<int>& costs,vector<int>& dp){
        dp[0]=0;
        dp[1]=dp[0]+costs[0]+(1);
        if(n>=2)dp[2]=min(dp[0]+costs[1]+(4),dp[1]+costs[1]+(1));

        for(int i=3;i<=n;i++){
            int x=min(dp[i-1]+costs[i-1]+1,dp[i-2]+costs[i-1]+4);
            dp[i]=min(x,dp[i-3]+costs[i-1]+9);
        }
        return dp[n];

    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1);
        return calculate(n,costs,dp);
    }
};