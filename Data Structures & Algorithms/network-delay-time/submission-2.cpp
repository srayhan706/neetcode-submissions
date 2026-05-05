class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for(auto &t : times){
            int u = t[0] - 1;
            int v = t[1] - 1;
            int wt = t[2];
            dist[u][v] = wt;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int res = *max_element(dist[k-1].begin(), dist[k-1].end());

        return (res == INT_MAX) ? -1 : res;
    }
};