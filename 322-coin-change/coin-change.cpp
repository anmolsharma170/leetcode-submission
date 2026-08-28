
class Solution {
public:
    int helper(vector<int> &coins,int amount,vector<int> &dp){
        if(amount==0) return 0;
        if(dp[amount]!=-2) return dp[amount];
        int res = INT_MAX;
        for(int i = 0;i<coins.size();i++){
            if(amount-coins[i]<0) continue;
            res = min(res,helper(coins,amount-coins[i],dp));
        }
        if(res==INT_MAX) return dp[amount]=INT_MAX;
        return dp[amount] = 1+res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1000006,-2);
        
        int ans = helper(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};