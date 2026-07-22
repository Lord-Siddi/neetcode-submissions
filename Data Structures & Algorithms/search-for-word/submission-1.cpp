class Solution {
public:
int n,m;
    bool solve(int i,int j,vector<vector<char>>&board,string word,vector<vector<bool>>&visited,int index){
        if(index==word.size())return true;
        if(i<0||j<0||i>=n||j>=m||visited[i][j]||board[i][j]!=word[index])return false;
        
        visited[i][j]=true;
        bool up=solve(i-1,j,board,word,visited,index+1);
        bool down=solve(i+1,j,board,word,visited,index+1);
        bool left=solve(i,j-1,board,word,visited,index+1);
        bool right=solve(i,j+1,board,word,visited,index+1);
        visited[i][j]=false;
        return up||down||left||right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>>visited(n,vector<bool>(m,false));
                
                if(solve(i,j,board,word,visited,0))return true;
                }
            }
        }
        return false;
    }
};
