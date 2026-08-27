class Solution {
public:
    int helperz(vector<int> nums,int i,vector<int> &dp){
        if(i >= nums.size()-1) return 0;
        // if(i==nums.size()-2) return nums[i];
        // if(i==nums.size()-3) return max(nums[i+1],nums[i+2]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+helperz(nums,i+2,dp),0+helperz(nums,i+1,dp));
    }
    int helper(vector<int> nums,int i,vector<int> &dp1){
        if(i >= nums.size()) return 0;
        // if(i==nums.size()-1) return nums[i];
        // if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp1[i]!=-1) return dp1[i];
        return dp1[i]=max(nums[i]+helper(nums,i+2,dp1),0+helper(nums,i+1,dp1));
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        vector<int> dp(nums.size(),-1);
        vector<int> dp1(nums.size(),-1);
        int x =  helperz(nums,0,dp);
        int y =  helper(nums,1,dp1);
        return max(x,y);
    }
};