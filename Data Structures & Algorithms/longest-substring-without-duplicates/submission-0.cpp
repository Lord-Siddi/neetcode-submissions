class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        int left=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>=2){
                mp[s[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi==INT_MIN?0:maxi;
    }
};
