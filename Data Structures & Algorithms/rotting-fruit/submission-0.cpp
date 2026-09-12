class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh_count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh_count++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (fresh_count == 0) {
            return 0;
        }
        int minutes = 0;
        while (!q.empty() && fresh_count > 0) {
            int size = q.size();
            minutes++;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int nr[] = {-1, 1, 0, 0};
                int nc[] = {0, 0, -1, 1};
                int row = p.first;
                int col = p.second;
                for (int d = 0; d < 4; d++) {
                    int new_row = row + nr[d];
                    int new_col = col + nc[d];
                    if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n ||
                        grid[new_row][new_col] != 1) {
                        continue;
                    }
                    grid[new_row][new_col] = 2;
                    q.push({new_row, new_col});
                    fresh_count--;
                }
            }}
            if (fresh_count != 0) {
                return -1;
            }
            return minutes;
        }
    };
