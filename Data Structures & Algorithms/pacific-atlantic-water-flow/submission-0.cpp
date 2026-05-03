class Solution {
public:
    int m,n;
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r,int c, vector<vector<bool>> &vis,vector<vector<int>>& heights){
        vis[r][c]=true;

        for(auto dir:dirs){
            int nr=r+dir.first;
            int nc=c+dir.second;

            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,vis,heights);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();


        vector<vector<bool>> pac(m,vector<bool> (n,false));
        vector<vector<bool>> atl(m,vector<bool> (n,false));

        for(int i=0;i<n;i++){
            dfs(0,i,pac,heights);
        }

        for(int i=0;i<m;i++){
            dfs(i,0,pac,heights);
        }

        for(int i=0;i<n;i++){
            dfs(m-1,i,atl,heights);
        }

        for(int i=0;i<m;i++){
            dfs(i,n-1,atl,heights);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
        
    }
};
