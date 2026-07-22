class Solution {
public:
    int robb(vector<int>&arr,int start,int end){
        int m1=0;
        int m2=0;
        for(int i=start;i<=end;i++){
            int current=max(m1,m2+arr[i]);
            m2=m1;
            m1=current;
        }
        return m1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        int case1=robb(nums,0,n-2);
        int case2=robb(nums,1,n-1);
        return max(case1,case2);
    }
};
