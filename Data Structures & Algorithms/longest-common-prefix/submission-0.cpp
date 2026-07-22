class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            string s=strs[i];
            int j=0;
            while(j<ans.size()&&j<s.size()&&ans[j]==s[j])j++;
            ans=s.substr(0,j);
            if(ans.empty())return "";
        }
        return ans;
    }
};