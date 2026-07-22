class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty())return;
        int n=grid.size();
        int m=grid[0].size();
        const int INF = 2147483647;

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        vector<pair<int,int>>dirs={
            {1,0},{0,1},{-1,0},{0,-1}
        };

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto[dx,dy]:dirs){
                int nx=x+dx;
                int ny=y+dy;

                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==INF){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
