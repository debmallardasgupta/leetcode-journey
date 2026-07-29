class Solution {
public:
    int total=0;
    bool cols[10]={false};
    bool diag1[20]={false};
    bool diag2[20]={false};

    void solve(int row,int n){
        if(row==n){
            total++;
            return;
        }
        for(int col=0;col<n;col++){
            if(cols[col]||diag1[row+col]||diag2[row-col+n])continue;
            cols[col]=diag1[row+col]=diag2[row-col+n]=true;
            solve(row+1,n);
            cols[col]=diag1[row+col]=diag2[row-col+n]=false;
        }
    }
    int totalNQueens(int n) {
        total=0;
        solve(0,n);
        return total;
    }
};