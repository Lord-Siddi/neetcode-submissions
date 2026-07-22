class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            if(mp.find(i)!=mp.end())return i;
            else mp[i]++;
        }
        return -1;
    }
};
