class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val)continue;
            swap(nums[curr],nums[i]);
            curr++;
        }
        return curr;
    }
};