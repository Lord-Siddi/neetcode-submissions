class Solution {
public:
    vector<int>dpMax,dpMin;
    pair<int,int>solve(vector<int>&nums,int i){
        if(i==0)return {nums[0],nums[0]};
        if(dpMax[i]!=INT_MIN){
            return {dpMax[i],dpMin[i]};
        }

        auto prev=solve(nums,i-1);

        int mx=prev.first;
        int mn=prev.second;

        int a=nums[i];
        int b=nums[i]*mx;
        int c=nums[i]*mn;

        dpMax[i]=max({a,b,c});
        dpMin[i]=min({a,b,c});
        return {dpMax[i],dpMin[i]};
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        dpMax.assign(n,INT_MIN);
        dpMin.assign(n,INT_MIN);
        int ans=nums[0];

        for(int i=0;i<nums.size();i++){
            auto p=solve(nums,i);
            ans=max(ans,p.first);
        }
        return ans;
    }
};
