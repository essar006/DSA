class Solution {
public:
    vector<pair<int, int>> dir{{0,1}, {0, -1}, {-1, 0}, {1,0}};
    vector<vector<bool>> vis;
    bool dfs (int row, int col, int m, int n, vector<vector<char>>& board, string word, int index){
        if(vis[row][col] || board[row][col] != word[index])
            return false;

        if(index == word.size()-1)
            return true;

        vis[row][col] = true;

        for(auto &d : dir){
            auto r = d.first + row;
            auto c = d.second + col;
            if(r>=0 && r<m && c>=0 && c<n){  
                if(dfs(r, c, m, n, board, word, index+1))
                    return true;
            }
        }

        vis[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                
                if(dfs(i, j, m, n, board, word, 0))
                    return true; 
            }
        }
        return false;
    }
};