class Solution {
public:
    vector<vector<bool>> vis;
    vector<pair<int, int>> dir{{0,1}, {0, -1}, {-1, 0}, {1,0}};

    void dfs (int row, int col, int m, int n, vector<vector<char>>& grid){
        vis[row][col] = true; 
        for(auto x : dir){
            auto r = x.first + row;
            auto c = x.second + col;
            if(r>=0 && r<m && c>=0 && c<n && vis[r][c] == false && grid[r][c] == '1')
                dfs(r, c, m, n, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    dfs(i, j, m, n, grid);
                    count++;
                }
            }
        }
        return count;
    }
};