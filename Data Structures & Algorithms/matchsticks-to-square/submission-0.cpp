class Solution {
public:
    bool dfs(int idx, vector<int>&nums, vector<int>&sides, int target){
        if(idx==nums.size())return true;

        for(int i=0;i<4;i++){
            if(sides[i]+nums[idx]>target)continue;
            sides[i]+=nums[idx];
            if(dfs(idx+1,nums,sides,target))return true;
            sides[i]-=nums[idx];
            if(sides[i]==0)break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);

        if(sum%4!=0)return false;

        int target=sum/4;

        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>target)return false;

        vector<int>sides(4,0);
        return dfs(0,matchsticks,sides,target);
    }
};