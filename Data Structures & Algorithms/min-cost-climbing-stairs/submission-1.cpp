class Solution {
public:
    int solve(vector<int>&cost,int index,vector<int>&dp){
        if(index>=cost.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int cost1=cost[index]+solve(cost,index+1,dp);
        int cost2=cost[index]+solve(cost,index+2,dp);
        return dp[index]=min(cost1,cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};
