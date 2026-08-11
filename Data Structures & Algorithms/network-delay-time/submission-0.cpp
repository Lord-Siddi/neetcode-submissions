class Solution {
public:
    vector<int>dijkstra(vector<vector<pair<int,int>>>&adj,int src,int n){


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>dist(n+1,INT_MAX);

        dist[src]=0;
        pq.emplace(0,src);

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int d=top.first;
            int u=top.second;

            if(d>dist[u]){
                continue;
            }
            for(auto &p:adj[u]){
                int v=p.first;
                int w=p.second;
                if(dist[v]>w+dist[u]){
                    dist[v]=w+dist[u];
                    pq.emplace(dist[v],v);
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        int ans = 0;
        vector<int>dist=dijkstra(adj,k,n);
        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
