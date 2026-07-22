class Solution {
public:
    vector<string>path;
    vector<vector<string>>res;
    bool isPalindrome(string &s,int left,int right){
        while(left<=right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(string s,int index){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int end=index;end<s.size();end++){
            if(isPalindrome(s,index,end)){
            path.push_back(s.substr(index,end-index+1));
            solve(s,end+1);
            path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return res;
    }
};
