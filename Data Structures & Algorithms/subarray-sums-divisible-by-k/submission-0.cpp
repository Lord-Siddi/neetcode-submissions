class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum=0,res=0;
        unordered_map<int,int>prefixCnt;
        prefixCnt[0]=1;
        for(int n:nums){
            prefixSum+=n;
            int remain=prefixSum%k;
            if(remain<0)remain+=k;
            res+=prefixCnt[remain];
            prefixCnt[remain]++;
        }
        return res;
    }
};