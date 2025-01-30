class Solution {
public:
    void solve(int col, vector<vector<string>>&ans, vector<string>&board, vector<int>&left, vector<int>&upper, vector<int>&lower, int n ){
        if(col == n){
            ans.push_back(board);
            return; 
        }
        for(int row=0; row<n; row++){
            if(left[row] ==0 && upper[n-1+row-col]==0 && lower[row+col]==0){
                board[row][col] = 'Q';
                left[row] = 1;
                upper[n-1+row-col] = 1;
                lower[row+col] = 1;

                solve(col+1,ans,board,left,upper,lower,n);

                board[row][col] = '.';
                left[row] = 0;
                upper[n-1+row-col] = 0;
                lower[row+col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int>leftrow(n,0),upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0,ans,board,leftrow,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
};