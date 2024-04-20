class Solution {
public:
    long long int f(vector<int>&arr){
        int n = arr.size();
        vector<int>dp(n,-1);
        dp[0]=arr[0];
        int neg=0;
        for(int i=1; i<n; i++){
            int pick = arr[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        vector<int>temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        long long int ans1 = f(temp1);
        long long int ans2 = f(temp2);
        return max(ans1,ans2);
    }
};