class Solution {
public:
    int m,n;

    void dfs(int r,int c,vector<vector<char>>& board){
        if(r<0 || r>=m || c<0 || c>=n || board[r][c] != 'O'){
            return;
        }
        board[r][c]='S';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        for(int i=0;i<n;i++){
            dfs(0,i,board);
            dfs(m-1,i,board);
        }

        for(int i=0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='S'){
                    board[i][j]='O';
                }
            }
        }
        
        
    }
};
