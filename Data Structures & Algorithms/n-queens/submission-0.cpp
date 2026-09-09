class Solution {
public:
    void n_queens(int n, vector<string>& board, vector<vector<string>>& result,
                  int row) {
        if (row == n) {
            result.push_back(board);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (ispossible(n, board, result, row, i)) {
                board[row][i] = 'Q';
                n_queens(n, board, result, row + 1);
                board[row][i] = '.';
            }
        }
    }
    bool ispossible(int n, vector<string>& board,
                    vector<vector<string>>& result, int row, int col) {
        // for row
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // for columsn
        for (int i = 0; i < n; i++) {
            if (board[row][col] == 'Q') {
                return false;
            }
        }
        // for diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // for right diagonal
        // for left diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        n_queens(n, board, result, 0);
        return result;
    }
};