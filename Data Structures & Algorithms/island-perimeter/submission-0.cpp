class Solution {
public:
    void solve(vector<vector<int>>&grid,vector<vector<bool>>&visited,int &perimeter,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            perimeter++;
            return;
        }
        if(grid[i][j]==0){
            perimeter++;
            return;
        }
        if(visited[i][j])return;
        visited[i][j]=true;
        solve(grid,visited,perimeter,i,j+1);
        solve(grid,visited,perimeter,i+1,j);
        solve(grid,visited,perimeter,i-1,j);
        solve(grid,visited,perimeter,i,j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int perimeter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    solve(grid,visited,perimeter,i,j);
                }
            }
        }
        return perimeter;

    }
};