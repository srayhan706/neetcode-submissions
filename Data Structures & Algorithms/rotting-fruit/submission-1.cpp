class Solution {
public:
    int m;
    int n;
    
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if(fresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }

        int time=-1;

        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                for(auto dir:dirs){
                    int nr=r+dir.first;
                    int nc=c+dir.second;

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 ){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh==0){
            return time;
        }

        return -1;
        
    }
};
