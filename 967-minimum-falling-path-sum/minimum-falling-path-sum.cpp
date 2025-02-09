class Solution {
public:
    int f(int i, int j ,vector<vector<int>>& mat, int n, vector<vector<int>>&dp){
        if(j<0 || j>=n) return INT_MAX;
        if(i==n-1){
            return mat[n-1][j];
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int down = f(i+1,j,mat,n,dp);
        int leftdi =  f(i+1,j-1,mat,n,dp);
        int ridi =  f(i+1,j+1,mat,n,dp);

        return dp[i][j] = mat[i][j] + min(down, min(leftdi,ridi));
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            int nas = f(0,j,mat,n,dp);
            mini = min(mini, nas);
        }
        return mini;
    }
};