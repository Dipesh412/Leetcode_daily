class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = INT_MAX,left=INT_MAX;
        if(i-1>=0){
            up = grid[i][j]+f(i-1,j,dp,grid);
        }
        if(j-1>=0){
            left = grid[i][j]+f(i,j-1,dp,grid);
        }
        return dp[i][j] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,grid);
    }
};