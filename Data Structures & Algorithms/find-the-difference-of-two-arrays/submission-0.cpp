class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>mp1;
       unordered_set<int>mp2;

       for(int i:nums1){
        mp1.insert(i);
       }
       for(int j:nums2){
        mp2.insert(j);
       }

       vector<vector<int>>ans(2);
       for(int i:nums1){
        if(!mp2.count(i)){
            ans[0].push_back(i);
            mp2.insert(i);
        }
       }
       for(int j:nums2){
        if(!mp1.count(j)){
            ans[1].push_back(j);
            mp1.insert(j);
        }
       }
       return ans;
    }
};