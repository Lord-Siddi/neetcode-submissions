class Solution {
public:
    int solve(vector<int>& nums, int prevIdx, int idx,
              vector<vector<int>>& dp) {

        if(idx==nums.size())
            return 0;

        if(dp[idx][prevIdx+1]!=-1)
            return dp[idx][prevIdx+1];

        int take=0;

        if(prevIdx==-1||nums[idx]>nums[prevIdx]){
            take=1+solve(nums,idx,idx+1,dp);
        }

        int notTake=solve(nums,prevIdx,idx+1,dp);

        return dp[idx][prevIdx + 1]=max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(nums,-1,0,dp);
    }
};