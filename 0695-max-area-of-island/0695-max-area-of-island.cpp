class Solution {
public:
    vector<vector<int>> dirs{{0,1}, {0,-1}, {1,0}, {-1,0}};

    int dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0; 

        int area = 1;   

        for (auto &d : dirs) {
            area += dfs(r + d[0], c + d[1], grid);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};
