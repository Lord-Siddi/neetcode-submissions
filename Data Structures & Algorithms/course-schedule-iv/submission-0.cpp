class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<vector<bool>>& reachable,
             int source) {

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;

                // source is a prerequisite of neighbor
                reachable[source][neighbor] = true;

                dfs(neighbor, adj, visited, reachable, source);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);

        for(auto& p:prerequisites){
            int u=p[0];
            int v=p[1];

            adj[u].push_back(v);
        }

        vector<vector<bool>>reachable(numCourses,vector<bool>(numCourses,false));

        for (int i = 0; i < numCourses; i++) {

            vector<bool> visited(numCourses, false);

            dfs(i, adj, visited, reachable, i);
        }

        vector<bool> answer;

        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];

            answer.push_back(reachable[u][v]);
        }

        return answer;
    }
};