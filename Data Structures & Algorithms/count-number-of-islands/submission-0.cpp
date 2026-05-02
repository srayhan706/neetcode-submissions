class Solution {
public:
    vector<vector<bool>> vis;
    int m;
    int n;
    vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int r,int c,vector<vector<char>>& grid){
        vis[r][c]=true;
        for(auto dir:dirs){
            int nr=r+dir.first;
            int nc=c+dir.second;


            if(nr<0 || nr>=m || nc<0 || nc>=n || vis[nr][nc] || grid[nr][nc]=='0'){
                continue;
            }
            dfs(nr,nc,grid);
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        m=grid.size();
        n=grid[0].size();

        int cnt=0;

        vis.assign(m,vector<bool> (n,false));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};
