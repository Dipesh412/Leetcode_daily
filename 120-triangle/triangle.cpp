class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,int n,vector<vector<int>>&triangle){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j] +f(i+1,j,dp,n,triangle);
        int dia = triangle[i][j]+f(i+1,j+1,dp,n,triangle);
        return dp[i][j] = min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // int m = triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,dp,n,triangle);
    }
};