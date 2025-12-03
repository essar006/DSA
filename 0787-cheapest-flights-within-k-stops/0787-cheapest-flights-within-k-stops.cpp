class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][stops] = minimum cost to reach node with stops
        vector<vector<int>> dist(n, vector<int>(K+2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});  // cost, node, stops

        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int cost = curr[0], u = curr[1], stops = curr[2];

            if(u == dst) return cost;
            if(stops > K) continue;

            for(auto &pr : adj[u]) {
                int v = pr.first;
                int w = pr.second;

                if(dist[v][stops+1] > cost + w) {
                    dist[v][stops+1] = cost + w;
                    pq.push({cost + w, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
