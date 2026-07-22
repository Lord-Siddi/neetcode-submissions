class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref;
        vector<int>suff;
        int mul=1;
        for(int i=0;i<nums.size();i++){
            pref.push_back(mul);
            mul*=nums[i];
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            suff.push_back(mul);
            mul*=nums[i];
        }
        reverse(suff.begin(),suff.end());
        for(int i=0;i<n;i++){
            nums[i]=pref[i]*suff[i];
        }
        return nums;
    }
};
