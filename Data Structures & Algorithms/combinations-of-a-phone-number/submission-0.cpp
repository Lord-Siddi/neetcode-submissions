class Solution {
public:
    void solve(string digits,int index,string curr,vector<string>&result,unordered_map<char,string>&mp){
        if(index==digits.size()){
            result.push_back(curr);
            return;
        }
        for(char c:mp[digits[index]]){
            curr.push_back(c);
            solve(digits,index+1,curr,result,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>res;
        unordered_map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        string curr;
        solve(digits,0,curr,res,mp);
        return res;
    }
};
