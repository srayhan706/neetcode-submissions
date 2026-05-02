class Solution {
public:
    vector<vector<int>> gr;
    vector<int> res;
    vector<int> indeg;
    


    void dfs(int i){
        res.push_back(i);
        indeg[i]--;
        for(int j:gr[i]){
            indeg[j]--;
            if(indeg[j]==0){
                dfs(j);
            }
        }


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n=numCourses;
        gr.assign(n,vector<int> ());
        indeg.assign(n,0);

        for(auto p:prerequisites){
            int v=p[0];
            int u=p[1];
            gr[u].push_back(v);
            indeg[v]++;
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                dfs(i);
            }

        }

        if(res.size() != n){
            return {};
        }

        return res;
        
    }
};
