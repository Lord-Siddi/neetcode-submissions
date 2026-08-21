class Solution {
public:
    int mySqrt(int x) {
        int high=x;
        int low=0;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(mid*mid==x)return mid;
            else if((long long)mid*mid>x)high=mid-1;
            else{
                low=mid+1;
                ans=mid;
            } 
        }
        return ans;
    }
};