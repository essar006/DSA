class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue; 
            color[start] = 1;
            queue<int> q;
            q.push(start);

            while(!q.empty()){
                int item = q.front();
                q.pop();
                for(auto x : graph[item]){ 
                    if(color[x] == -1){
                        color[x] = 1-color[item];
                        q.push(x);
                    }
                    else if(color[item] == color[x]) {
                        return false; 
                    }
                }
            }  
        }
        return true;
    }
};