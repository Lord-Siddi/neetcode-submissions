class Solution {
public:
    bool solve(vector<int>&nums,int idx,int target,vector<vector<int>>&dp){
        if(target==0)return true;

        if(idx==nums.size()||target<0)return false;
        if(dp[idx][target]!=-1)return dp[idx][target];
        int take=solve(nums,idx+1,target-nums[idx],dp);
        int notTake=solve(nums,idx+1,target,dp);
        return dp[idx][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum%2==1)return false;
        int target=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};
