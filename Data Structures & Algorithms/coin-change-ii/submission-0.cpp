class Solution {
public:
    int solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(index==coins.size()||amount<0)return 0;
        if(dp[index][amount]!=-1)return dp[index][amount];
        int count=0;

        count+=solve(coins,amount-coins[index],index,dp);
        count+=solve(coins,amount,index+1,dp);
        return dp[index][amount]=count;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,index,dp);
    }
};
