class Solution {
public:
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    int m;
    int n;

    bool dfs(int r,int c,int k,string &word,vector<vector<char>>& board){

        if(k==word.size()){
            return true;
        }

        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!=word[k]){
            return false;
        }

        char tmp=board[r][c];
        board[r][c]='#';
        bool found= dfs(r+1,c,k+1,word,board)|| 
                    dfs(r-1,c,k+1,word,board)||
                    dfs(r,c+1,k+1,word,board)|| 
                    dfs(r,c-1,k+1,word,board);

        board[r][c]=tmp;
        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,word,board)){
                    return true;
                }
            }
        }

        return false;
        
    }
};
