class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>>adj;
        unordered_map<char,int>indegree;

        for(auto &word:words){
            for(char c:word){
                indegree[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string a=words[i],b=words[i+1];
            if(a.size()>b.size()&&a.substr(0,b.size())==b)return "";
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    adj[a[j]].push_back(b[j]);
                    indegree[b[j]]++;
                    break;
                }
            }
        }
        queue<char>q;
        for(auto it:indegree){
            if(it.second==0)q.push(it.first);
        }
        string result="";
        while(!q.empty()){
            char node=q.front();
            q.pop();
            result+=node;
            for(int n:adj[node]){
                indegree[n]--;
                if(indegree[n]==0)q.push(n);
            }
        }
        if(result.size()!=indegree.size())return "";
        return result; 
    }
};
