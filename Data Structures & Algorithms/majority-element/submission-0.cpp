class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int currEle=nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==currEle){
                count++;
            }else{
                count--;
                if(count<0){
                    currEle=nums[i];
                    count=1;
                }
            }
        }
        return currEle;
    }
};