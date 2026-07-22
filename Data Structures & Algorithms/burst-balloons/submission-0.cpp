class Solution {
public:
    int solve(int left,int right,vector<int>&nums,vector<vector<int>>&dp){
        if(right-left<=1)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans=0;

        for(int k=left+1;k<right;k++){
            ans=max(ans,solve(left,k,nums,dp)+solve(k,right,nums,dp)+nums[left]*nums[right]*nums[k]);
        }
        return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);

        for(int x:nums){
            arr.push_back(x);
        }
        arr.push_back(1);
        int m=arr.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,arr.size()-1,arr,dp);
    }
};