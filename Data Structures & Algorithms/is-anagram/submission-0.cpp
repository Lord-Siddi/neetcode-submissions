class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(char c:s){
            mp1[c-'a']++;
        }
        for(char c:t){
            mp2[c-'a']++;
        }
        return mp1==mp2;
    }
};
