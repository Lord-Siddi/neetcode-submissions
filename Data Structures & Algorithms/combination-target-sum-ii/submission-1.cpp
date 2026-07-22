class Solution {
public:
    void solve(vector<int>&candidates,int target,vector<int>&curr,vector<vector<int>>&res,int index){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],curr,res,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;

        sort(candidates.begin(),candidates.end());

        solve(candidates,target,curr,res,0);
        return res;
    }
};
