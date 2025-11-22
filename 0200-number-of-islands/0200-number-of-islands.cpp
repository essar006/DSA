class Solution {
public:
    vector<vector<bool>> vis;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        vis = vector<vector<bool>>(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1},{0, -1},{1, 0},{-1, 0}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    q.push({i, j});
                    while(!q.empty()){
                        auto var = q.front();
                        int x = var.first;
                        int y = var.second;
                        q.pop();
                        for(auto& dir : dirs){
                            int row = x + dir.first;
                            int col = y + dir.second;
                            if(row >= 0 && row < m && col >= 0 && col < n && vis[row][col] == false && grid[row][col] == '1'){
                                vis[row][col] = true;
                                q.push({row, col});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};