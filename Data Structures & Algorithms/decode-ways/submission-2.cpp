class Solution {
public:
    int solve(string s,int index,vector<int>&dp){
        int n=s.length();

        if(index>=n)return 1;
        if(dp[index]!=-1)return dp[index];
        int ways=0;
        if(s[index]!='0'){
            ways=solve(s,index+1,dp);
        }
        if((index+1<n)&&((s[index]=='1'&&s[index+1]<='9')||(s[index]=='2'&&s[index+1]<='6'))){
            ways+=solve(s,index+2,dp);
        }
        return dp[index]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(s,0,dp);
    }
};
