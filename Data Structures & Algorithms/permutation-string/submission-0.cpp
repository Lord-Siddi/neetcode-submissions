class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);
        for(char c:s1){
            freq[c-'a']++;
        }
        int size=s1.size();
        int left=0;
        vector<int>freq1(26,0);
        for(int right=0;right<s2.size();right++){
            freq1[s2[right]-'a']++;
            while(right-left+1>size){
                freq1[s2[left]-'a']--;
                left++;
            }
            if(freq==freq1)return true;
        }
        return false;

    }
};
