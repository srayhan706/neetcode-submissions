class Solution {
public:
    bool dfs(int node, vector<vector<int>>& gr, vector<int>& state){
        if(state[node] == 1) return true;   // cycle found
        if(state[node] == 2) return false;  // already processed

        state[node] = 1; // mark as visiting

        for(int nei : gr[node]){
            if(dfs(nei, gr, state)){
                return true;
            }
        }

        state[node] = 2; // mark as done
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);

        for(auto &p : prerequisites){
            gr[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(dfs(i, gr, state)){
                return false;
            }
        }

        return true;
    }
};