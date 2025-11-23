class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        if(grid.empty()) return -1;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int FreshO = 0;
        int minute = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j] == 1)
                    FreshO++;
            }
        }

        if (FreshO == 0) return 0;

        while (!q.empty() && FreshO > 0) {
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for (auto &dir : dirs) {
                    int row = x + dir.first;
                    int col = y + dir.second;
                    
                    if (row >= 0 && row < m &&
                        col >= 0 && col < n &&
                        vis[row][col] == -1 &&
                        grid[row][col] == 1) 
                    {
                        FreshO--;
                        vis[row][col] = 0;
                        grid[row][col] = 2;
                        q.push({row, col});
                        
                    }
                }
            }
            minute++;
        }
        return FreshO == 0 ? minute : -1;
    }
};