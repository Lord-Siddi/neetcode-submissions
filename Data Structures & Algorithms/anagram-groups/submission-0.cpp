class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string i:strs){
            string sorted=i;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(i);
        }
        vector<vector<string>>res;
        for(auto &a:mp){
            res.push_back(a.second);
        }
        return res;
    }
};
