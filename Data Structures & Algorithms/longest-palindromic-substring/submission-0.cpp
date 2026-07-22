class Solution {
public:
    pair<int,int>expand(string &s,int a,int b){
        while(a>=0&&b<s.length()&&s[a]==s[b]){
            a--;
            b++;
        }
        return make_pair(a+1,b-a-1);
    }
    string longestPalindrome(string s) {
        int start=0,maxLen=1;
        for(int i=0;i<s.length();i++){
            auto [l1,len1]=expand(s,i,i);
            if(len1>maxLen){
                maxLen=len1;
                start=l1;
            }
            auto [l2,len2]=expand(s,i,i+1);
            if(len2>maxLen){
                maxLen=len2;
                start=l2;
            }
        }
        return s.substr(start,maxLen);
    }
};
