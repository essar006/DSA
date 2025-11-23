class Solution {
public:
    vector<pair<int, int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {1,0}, {1,1}, {1, -1}, {0, -1}, {0,1}};
    int n;
    vector<vector<bool>> vis;
    int minRes = 1;
    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();

                if(x == n-1 && y == n-1)
                    return minRes;

                for (auto &dir : dirs) {
                    int row = x + dir.first;
                    int col = y + dir.second;
                    
                    if (row >= 0 && row < n &&
                        col >= 0 && col < n &&
                        !vis[row][col] &&
                        grid[row][col] == 0) 
                    {
                        vis[row][col] = true;
                        q.push({row, col});
                        
                    }
                }
            }
            minRes++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        queue<pair<int, int>> q;
        
        int res = 0;
        n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vis = vector<vector<bool>>(n, vector<bool>(n, false));
        return bfs(0, 0, grid);
    }
};