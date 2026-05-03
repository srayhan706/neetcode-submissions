class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()!=n-1){
            return false;
        }

        vector<vector<int>> adj(n,vector<int> ());

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(int i:adj[node]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }

        return cnt==n;

    }
};
