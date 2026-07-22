class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        while(i<2*n){
            ans.push_back(nums[i%n]);
            i++;
        }
        return ans;
    }
};