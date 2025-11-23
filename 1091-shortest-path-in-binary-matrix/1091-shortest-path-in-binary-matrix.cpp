class Solution {
public:
    vector<pair<int, int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {1,0}, {1,1}, {1, -1}, {0, -1}, {0,1}};
    int n;
    vector<vector<int>> vis;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;

        n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vis = vector<vector<int>>(n, vector<int>(n, -1));
        vis[0][0] = 1;

        queue<pair<int,int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return vis[x][y];

            for (auto &dir : dirs) {
                int row = x + dir.first;
                int col = y + dir.second;
                
                if (row >= 0 && row < n &&
                    col >= 0 && col < n &&
                    vis[row][col] == -1 &&
                    grid[row][col] == 0) 
                {
                    vis[row][col] = vis[x][y] + 1;
                    q.push({row, col});
                    
                }
            }
        }
        return -1;
    }
};