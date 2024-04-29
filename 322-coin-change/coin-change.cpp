class Solution {
public:
    int f(vector<int>&arr,int ind,int T,vector<vector<long>>&dp){
        if(ind==0){
            if(T%arr[0]==0){
                return T/arr[ind];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][T]!=-1){
            return dp[ind][T];
        }
        long notTaken = f(arr,ind-1,T,dp);
        long Taken = 1e9;
        if(arr[ind]<=T){
            Taken =1+ f(arr,ind,T-arr[ind],dp);
        }
        return dp[ind][T] = min(notTaken,Taken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long>>dp(n,vector<long>(amount+1,-1));
        
        int ans =  f(coins,n-1,amount,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};