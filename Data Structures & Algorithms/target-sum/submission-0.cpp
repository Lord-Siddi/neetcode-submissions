class Solution {
public:
    int count=0;
    int solve(vector<int>&nums,int target,int index){
        if(target==0&&index==nums.size()){
            return 1;
        }
        if(index==nums.size()){
            return 0;
        }
        int count=0;
        count+=solve(nums,target-nums[index],index+1);
        count+=solve(nums,target+nums[index],index+1);
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,0);
    }
};
