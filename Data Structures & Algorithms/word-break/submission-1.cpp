class Solution {
public:
    unordered_set<string>st;
    int n;
    int solve(int idx,string s,vector<int>&dp){
        if(idx>=n)return true;
        if(dp[idx]!=-1)return dp[idx];

        if(st.find(s)!=st.end())return true;
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end()&&solve(idx+l,s,dp))return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        vector<int>dp(n,-1);
        for(string &word:wordDict){
            st.insert(word);
        }
        return solve(0,s,dp);
    }
};
