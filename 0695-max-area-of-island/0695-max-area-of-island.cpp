class Solution {
public:
    vector<pair<int, int>> dir{{0,1}, {0, -1}, {-1, 0}, {1,0}};
    vector<vector<bool>> vis;

    int dfs(int row, int col, int m, int n, vector<vector<int>> &grid){
        if(row<0 || col <0 || row >=m || col >= n || vis[row][col] || grid[row][col] == 0)
            return 0;
        vis[row][col] = true;
        int curArea = 1;
        for(auto &d : dir){
            int nx = row + d.first;
            int ny = col + d.second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1)
                curArea += dfs(nx, ny, m, n, grid);
        }
        return curArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        int maxArea = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == false && grid[i][j] == 1)
                {
                    int currArea = dfs(i, j, m, n, grid);
                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};