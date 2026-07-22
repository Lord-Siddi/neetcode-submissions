class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=INT_MIN;
        int n=heights.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int area=min(heights[left],heights[right])*(right-left);
            maxi=max(area,maxi);
            if(heights[left]>heights[right])right--;
            else left++;
        }
        return maxi;
    }
};
