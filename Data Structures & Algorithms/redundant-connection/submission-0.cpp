class Solution {
public:
    bool hascycle(int node,int parent,vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;

        for(int nei : adj[node]) {
            if(!vis[nei]) {
                if(hascycle(nei, node, vis, adj)) return true;
            }
            else if(nei != parent) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<vector<int>> adj(n+1);

       for(auto e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n+1, false);

            if(hascycle(u, -1, vis,adj)) {
                return {u, v};
            }
       }

       return {};
            

            
    }
};
