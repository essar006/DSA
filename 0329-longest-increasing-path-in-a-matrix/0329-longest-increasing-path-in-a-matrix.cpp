class Solution {
public:
    vector<vector<int>> t; //to memoize
    vector<pair<int, int>> dirs{{0,1},{0, -1}, {-1, 0}, {1, 0}};
    int dfs(int row, int col, vector<vector<int>>& matrix, int m, int n){
        if(t[row][col] > 1) return t[row][col];

        for(auto& dir : dirs)
        {
            int newR = row + dir.first;
            int newC = col + dir.second;
            if(newR >= 0 && newC >= 0 && newR < m && newC < n && matrix[newR][newC] > matrix[row][col])
                t[row][col] = max(t[row][col], 1+dfs(newR, newC, matrix, m, n));
        }
        return t[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        t = vector<vector<int>>(m, vector<int>(n, 1));
        int maxL = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++){
                maxL = max(maxL, dfs(i, j, matrix, m, n));
            }
        }

        return maxL == -1 ? 0 : maxL;
    }
};