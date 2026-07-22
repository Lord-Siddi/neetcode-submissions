class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>arr(26,0);

        int left=0;
        int maxi=INT_MIN;
        char maxChar='#';
        int maxFreq=0;

        for(int right=0;right<s.size();right++){
            if(maxChar=='#')maxChar=s[right];

            arr[s[right]-'A']++;
            if(maxFreq<arr[s[right]-'A']){
                maxFreq=arr[s[right]-'A'];
                maxChar=s[right];
            }
            while(right-left+1-maxFreq>k){
                arr[s[left]-'A']--;
                if(s[left]-'A'==maxChar)maxFreq--;
                left++;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};
