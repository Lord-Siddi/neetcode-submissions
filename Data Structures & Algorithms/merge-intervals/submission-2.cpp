class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=1;
        res.push_back(intervals[0]);
        while(i<n){
            if(res.back()[1]>=intervals[i][0]) res.back()[1]=max(intervals[i][1],res.back()[1]);
            else res.push_back(intervals[i]);
            i++;
        }
        return res;
        }
    
};
