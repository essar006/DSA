class Solution {
public:
    vector<vector<string>> res;
    vector<string> v;
    vector<vector<int>> grid; 
    vector<vector<string>> solveNQueens(int n) {
        grid = vector<vector<int>>(n, vector<int>(n, 0));
        dfs(n, 0); 

        return res;
    }

    void dfs(int n, int idx){
        if(idx == n){
            res.push_back(v);
            return;
        }

        for(int i=0; i<n; i++){
            if(canPut(i, idx, n)){
                grid[i][idx] = 1;
                v.push_back(getStr(n, i));
                dfs(n, idx+1);
                v.pop_back();
                grid[i][idx] = 0;
            }
        }
    }

    bool canPut(int row, int col, int n){ // <sabya.sachi>
        for(int i=0; i<col; i++){   //same row (left)
            if(grid[row][i] == 1)
                return false;
        }

        for(int i = row+1, j = col-1; i < n && j >=0; i++, j--) { //lower left dia
            if(grid[i][j] == 1) return false; 
        }

        for(int i = row-1, j = col-1; i >= 0 && j >=0; i--, j--) { //upper left dia
            if(grid[i][j] == 1) return false; 
        }

        return true;
    }

    string getStr(int n, int col){
        string s(n, '.');
        s[col] = 'Q';
        return s;
    }
};