class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pres) {
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> in(n, 0);
        int count = 0;
        for(auto& pre : pres){
            adj[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }

        for(int i=0; i<n; i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;

            for(auto& nei : adj[curr]){
                in[nei]--;
                if(in[nei] == 0) q.push(nei);
            }
        }
        return count == n;
    }
};