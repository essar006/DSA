class Solution {
public:
    vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        visited = vector<int>(numCourses, 0);
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                if(dfs(i, adj)) return false;
            }
        }
        return true;
    }

    bool dfs(int node, vector<vector<int>>& adj)
    {
        visited[node] = 1;

        for(auto nei : adj[node]){
            if(visited[nei] == 0){
                if(dfs(nei, adj)) return true;
            }
            if(visited[nei] == 1)
                return true;
        }
        visited[node] = 2;
        return false;
    }
};  