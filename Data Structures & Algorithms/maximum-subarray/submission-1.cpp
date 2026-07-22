class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            curr=max(curr+nums[i],nums[i]);
            if(curr>maxi){
                maxi=curr;
            }
        }
        return maxi;
    }
};
