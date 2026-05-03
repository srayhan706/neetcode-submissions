class Solution {
public:

    void dfs(int i,vector<bool> &vis,vector<vector<int>>& gr){
        vis[i]=true;
        for(int j:gr[i]){
            if(!vis[j]){
                dfs(j,vis,gr);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n,vector<int> ());

        for(auto e:edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }

        int cnt=0;

        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,gr);
                cnt++;
            }
        }

        return cnt;

    }
};
