class Solution {
public:
    vector<vector<int>>res;
    void backtrack(int n,int k,vector<int>&curr,int idx){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<=n;i++){
            curr.push_back(i);
            backtrack(n,k,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        backtrack(n,k,curr,1);
        return res;
    }
};