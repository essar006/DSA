class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> currRes;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        backtrack(0, currRes, res, grid, n);
        return res;
    }

private:
    bool check(int rowIdx, int colIdx, vector<vector<int>>& grid, int n) {
        for (int i = 0; i < colIdx; ++i) {
            if (grid[rowIdx][i] == 1) {
                return false;
            }
        }

        for (int i = rowIdx, j = colIdx; i >= 0 && j >= 0; --i, --j) {
            if (grid[i][j] == 1) {
                return false;
            }
        }

        for (int i = rowIdx, j = colIdx; i < n && j >= 0; ++i, --j) {
            if (grid[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    void backtrack(int colIdx, vector<string>& currRes, vector<vector<string>>& res, vector<vector<int>>& grid, int n) {
        if (colIdx == n) {
            res.push_back(currRes);
            return;
        }

        for (int rowIdx = 0; rowIdx < n; ++rowIdx) {
            if (check(rowIdx, colIdx, grid, n)) {
                grid[rowIdx][colIdx] = 1;
                currRes.push_back(getQueenRow(n, rowIdx));
                backtrack(colIdx + 1, currRes, res, grid, n);
                currRes.pop_back();
                grid[rowIdx][colIdx] = 0;
            }
        }
    }

    string getQueenRow(int n, int val) {
        string row(n, '.');
        row[val] = 'Q';
        return row;
    }
};
