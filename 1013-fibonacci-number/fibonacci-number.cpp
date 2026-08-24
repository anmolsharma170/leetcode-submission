class Solution {
public:
    int fibo(vector<int> &dp,int n){   // dp+memoization
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]=fibo(dp,n-1)+fibo(dp,n-2);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(dp,n);
    }
};