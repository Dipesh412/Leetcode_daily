class Solution {
public:
    long long f(vector<vector<int>>& questions,long long i,vector<long long>&dp){
       
        
        if(i>=questions.size() ){
           
            return 0;
        }
        
         if(dp[i] != -1){
            return dp[i];
        }
       
       
        long long take  = questions[i][0] + f(questions,i+questions[i][1]+1,dp);
        
       
       
       
        long long nottake = f(questions,i+1,dp);
        
        return dp[i] = max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
      
        int i=0;
        return f(questions,i,dp);
    }
};