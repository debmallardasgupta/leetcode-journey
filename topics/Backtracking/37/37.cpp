class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int dig){
        for(int i=0;i<9;i++){
            if(board[row][i]==dig){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==9){
            return true;
        }
        int nextRow=row, nextCol=col+1;
        if(nextCol==9){
            nextRow=row+1;
            nextCol=0;
        }
        if(board[row][col]!='.'){
            return solve(board, nextRow, nextCol);
        }
        for(char i='1';i<='9';i++){
            if(isSafe(board, row, col, i)){
                board[row][col]=i;
                if(solve(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};