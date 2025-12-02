class Solution {
public:
    vector<vector<string>> res;
    vector<string> v;

    vector<int> rowUsed;
    vector<int> diag1;
    vector<int> diag2;

    vector<vector<string>> solveNQueens(int n) {
        rowUsed = vector<int>(n, 0);
        diag1   = vector<int>(2*n - 1, 0);
        diag2   = vector<int>(2*n - 1, 0);

        dfs(n, 0);
        return res;
    }

    void dfs(int n, int col) {
        if (col == n) {
            res.push_back(v);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (canPut(row, col, n)) {
                // mark used
                rowUsed[row] = 1;
                diag1[row + col] = 1;
                diag2[row - col + (n - 1)] = 1;

                v.push_back(getStr(n, row));

                dfs(n, col + 1);

                // backtrack
                v.pop_back();
                rowUsed[row] = 0;
                diag1[row + col] = 0;
                diag2[row - col + (n - 1)] = 0;
            }
        }
    }

    bool canPut(int row, int col, int n) {
        if (rowUsed[row]) return false;
        if (diag1[row + col]) return false;
        if (diag2[row - col + (n - 1)]) return false;

        return true;
    }

    string getStr(int n, int row) {
        string s(n, '.');
        s[row] = 'Q';
        return s;
    }
};
