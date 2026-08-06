class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>>q;

        bool found=false;

        for(int r=0;r<n;r++){
            if(found)break;

            for(int c=0;c<n;c++){
                if(grid[r][c]==1){
                    queue<pair<int,int>>q1;

                    q1.push({r,c});
                    grid[r][c]=2;

                    while(!q1.empty()){
                        auto[x,y]=q1.front();q1.pop();

                        q.push({x,y});

                        for(auto& d:dir){
                            int nx=x+d[0],ny=y+d[1];

                            if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]==1){
                                grid[nx][ny]=2;
                                q1.push({nx,ny});
                            }
                        }
                    }
                    found=true;
                    break;
                }
            }
        }
        int res=0;
        while(!q.empty()){
            for(int i=q.size();i>0;i--){
                auto[x,y]=q.front();
                q.pop();

                for(auto&d:dir){
                    int nx=x+d[0],ny=y+d[1];

                    if(nx>=0&&ny>=0&&nx<n&&ny<n){
                        if(grid[nx][ny]==1)return res;
                        if(grid[nx][ny]==0){
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            res++;
        }
        return res;
    }
};