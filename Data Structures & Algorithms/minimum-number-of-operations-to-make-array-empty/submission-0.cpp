class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int num:nums){
            count[num]++;
        }
        int res=0;
        for(auto&[num,cnt]:count){
            if(cnt==1)return -1;
            res+=(cnt+2)/3;
        }
        return res;
    }
};