class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int num1=nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(num1+nums[left]+nums[right]==0){
                    res.push_back({num1,nums[left],nums[right]});
                    left++;
                    while(left<right&&nums[left]==nums[left-1])left++;
                    right--;
                    while(left<right&&nums[right]==nums[right+1])right--;
                }
                else if(num1+nums[left]+nums[right]>0){
                        right--;
                        while(left<right&&nums[right]==nums[right+1])right--;
                }else{
                    left++;
                    while(left<right&&nums[left]==nums[left-1])left++;
                }
            }
        }
        return res;
    }
};
