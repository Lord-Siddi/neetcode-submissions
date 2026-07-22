class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        heights.push_back(0);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int right=i;
                int left=st.empty()?0:st.top()+1;
                int width=right-left;
                maxi=max(maxi,h*width);
            }
            st.push(i);
        }
        return maxi;
    }
};
