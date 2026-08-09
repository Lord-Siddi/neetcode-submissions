class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);

        for(const auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return dfs(0,-1,adj,hasApple);
    }
    int dfs(int cur,int parent, vector<vector<int>>&adj,vector<bool>&hasApple){
        int time=0;

        for(int child:adj[cur]){
            if(child==parent)continue;
            int childTime=dfs(child,cur,adj,hasApple);
            if(childTime>0||hasApple[child])time+=2+childTime;
        }
        return time;
    }
};