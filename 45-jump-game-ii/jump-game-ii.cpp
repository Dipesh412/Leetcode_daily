class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp,int cnt){
        if(i>=nums.size()) return 100000;
        if(i==nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=100000;
        for(int j=i+1;j<=i+nums[i];j++){
            int cur=1+solve(j,nums,dp,cnt);
            maxi=min(maxi,cur);
            
        }
        return dp[i]=maxi;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp,0);
    }
};