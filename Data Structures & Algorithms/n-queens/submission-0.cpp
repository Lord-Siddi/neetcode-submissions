class Solution {
public:
    vector<vector<string>>ans;
    int n;
    bool isSafe(int row,int col,vector<string>&board){
        for(int r=0;r<row;r++){
            if(board[r][col]=='Q')return false;
        }
        for(int r=row-1,c=col-1;r>=0&&c>=0;r--,c--){
            if(board[r][c]=='Q')return false;
        }
        for(int r=row-1,c=col+1;r>=0&&c<n;r--,c++){
            if(board[r][c]=='Q')return false;
        }
        return true;
    }
    void solve(int row,vector<string>&board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(row,i,board)){
                board[row][i]='Q';
                solve(row+1,board);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        this->n=n;
        solve(0,board);
        return ans;
    }
};
