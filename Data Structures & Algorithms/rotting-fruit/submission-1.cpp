class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        if(q.empty())return -1;
        vector<pair<int,int>>dirs={
            {1,0},{-1,0},{0,1},{0,-1}
        };
        
        int mini=0;
        while(!q.empty()){
            int s=q.size();
            bool rotted=false;
            for(int i=0;i<s;i++){

            auto[x,y]=q.front();
            q.pop();
            for(auto[dx,dy]:dirs){
                int nx=x+dx,ny=y+dy;
                if(ny>=0&&ny<m&&nx>=0&&nx<n&&grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    fresh--;
                    rotted=true;
                }
            }
            }
            if(rotted)mini++;
            
        }
        return(fresh==0)?mini:-1;

    }
};
