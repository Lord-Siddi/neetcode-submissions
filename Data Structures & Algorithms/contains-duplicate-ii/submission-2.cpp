class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0;
        unordered_map<int,int>mp;
        for(int right=0;right<nums.size();right++){
            if(mp[nums[right]]>0)return true;
            mp[nums[right]]++;
            if(right-left>=k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};