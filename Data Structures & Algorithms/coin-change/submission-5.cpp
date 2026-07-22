class Solution {
public:
    int solve(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        if(dp[amount]!=-1)return dp[amount];
        int mini=1e9;
        for(int coin:coins){
            mini=min(mini,1+solve(coins,amount-coin,dp));
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,INT_MAX);
       dp[0]=0;
       for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0&&dp[i-coin]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
       }
       return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
