class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char val){
        //same row check
        for(int i=0; i<9; i++){
            if(board[row][i] == val)
                return false;
            if(board[i][col] == val)
                return false;
        }
        
        //<sabya.sachi>
        //basically this is to find the starting index of the 3×3 subgrid (box) that contains a given cell at (row, col) on the 9×9 Sudoku board.
        int xx = (row/3) * 3; 
        int yy = (col/3) * 3;

        for(int i=xx; i<xx+3; i++){
            for(int j=yy; j<yy+3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }

        return true;
    }

    //bool return type to terminate early once a valid solution is found <sabya.sachi>
    //idea is to traverse cell by cell and check each possibility
    bool solve(vector<vector<char>> &board, int row, int col){ 
        if(row == 9)
            return true;
        if(col == 9){
            return solve(board, row+1, 0);
        }

        if(board[row][col] != '.')
            return solve(board, row, col+1);
        else {
            for(int i=1; i<=9; i++){
                char val = '0'+i;
                if(check(board, row, col, val)){
                    board[row][col] = val;
                    if(solve(board, row, col+1)) return true;
                    board[row][col] = '.'; //backtrack
                }
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> res;
        solve(board, 0, 0); 
    }
};