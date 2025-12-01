class Solution {
private:
    vector<pair<int, int>> dir{{0,1},{0,-1},{-1,0},{1,0}};

    void dfs(int r, int c, vector<vector<bool>>& ocean, int m, int n, vector<vector<int>>& heights) {
    ocean[r][c] = true;
    
    for (auto& d : dir) {
        int nextRow = r + d.first;
        int nextCol = c + d.second;
        
        if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && !ocean[nextRow][nextCol] && heights[nextRow][nextCol] >= heights[r][c]) {
            dfs(nextRow, nextCol, ocean, m, n, heights);
        }
    }
}

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;

        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<bool>> pac(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dfs(0, i, pac, m, n, heights);
            dfs(m - 1, i, atl, m, n, heights);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac, m, n, heights);
            dfs(i, n - 1, atl, m, n, heights);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atl[i][j] && pac[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
