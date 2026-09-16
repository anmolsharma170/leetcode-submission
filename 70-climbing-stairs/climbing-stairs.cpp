class Solution {
public:
    int count(int n, vector<int>& dp){
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i = 3;i<=45;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];  
    }
    int climbStairs(int n) {
        vector<int> dp(50,-1);
        return count(n, dp);
    }
};