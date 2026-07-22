class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>&nums,int target,int index,vector<int>&curr){
        if(0==target){result.push_back(curr);
            return;
        }
        if(target<0||index==nums.size())return;
        curr.push_back(nums[index]);
        backtrack(nums,target-nums[index],index,curr);
        curr.pop_back();
        backtrack(nums,target,index+1,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<int>curr;
     backtrack(nums,target,0,curr);
     return result;   
    }
};
