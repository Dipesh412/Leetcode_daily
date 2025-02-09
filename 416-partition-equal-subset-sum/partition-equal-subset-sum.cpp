class Solution {
public:
    bool f(int ind, vector<int>&nums, int tar, vector<vector<int>>&dp){
        if(tar==0){
            return true;
        }
        if(ind == 0){
            if(tar==nums[0]){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        bool nottake = f(ind-1,nums,tar,dp);
        bool take = false;
        if(nums[ind] <= tar) {
            take = f(ind-1,nums,tar-nums[ind],dp);
        }
        return dp[ind][tar] = nottake || take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i]; 
        }
        int s = sum /2;
        vector<vector<int>>dp(n, vector<int>(s+1,-1));
        if(sum % 2 == 1) return false;
        return f(n-1,nums,s,dp);
    }
};