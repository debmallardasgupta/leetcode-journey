class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, ans);
        return ans;
    }
};