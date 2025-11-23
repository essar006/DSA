class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) {
            return -1;
        }
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = 1; 
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // 8 directions: horizontal, vertical, and diagonal
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // If we've reached the destination
            if (i == m-1 && j == n-1) {
                return visited[i][j];
            }
            
            // Check all 8 directions
            for (auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                
                if (isValid(ni, nj, m, n) && grid[ni][nj] == 0 && visited[ni][nj] == -1) {
                    visited[ni][nj] = visited[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return -1; // No path found
    }
};