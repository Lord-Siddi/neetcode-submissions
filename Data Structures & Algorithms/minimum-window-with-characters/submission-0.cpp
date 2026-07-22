class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(t.length()>n)return "";

        unordered_map<char,int>mp;

        for(char&ch:t){
            mp[ch]++;
        }
        int required=t.size();
        int left=0;
        int window=INT_MAX;
        int start=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            if(mp[ch]>0)required--;
            mp[ch]--;
            while(required==0){
                int curr=right-left+1;
                if(window>curr){
                    window=curr;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0)required++;
                left++;
            }
        }
        return window==INT_MAX?"":s.substr(start,window);
    }
};
