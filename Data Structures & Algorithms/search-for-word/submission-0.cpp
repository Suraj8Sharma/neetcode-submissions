class Solution {
public:
    
    bool dfs(int r, int c, int m, int n, vector<vector<char>>& board, string& word, int index,
             vector<vector<bool>>& visited) {
        
        if (index == word.size()) {
            return true;
        }
        
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == true ||
            word[index] != board[r][c]) {
            return false;
        }
        
        visited[r][c] = true;
        
        bool found = dfs(r + 1, c, m, n, board, word, index + 1, visited) ||
                     dfs(r - 1, c, m, n, board, word, index + 1, visited) ||
                     dfs(r, c - 1, m, n, board, word, index + 1, visited) ||
                     dfs(r, c + 1, m, n, board, word, index + 1, visited);
                     
        visited[r][c] = false;
        
       
        return found; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
       
                    if (dfs(i, j, m, n, board, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        
      
        return false; 
    }
};