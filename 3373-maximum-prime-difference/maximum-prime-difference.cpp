class Solution {
public:
    bool check(int value){
        if(value<=1){
            return false;
        }
      
        for(int i=2; i<=value/2; i++){
            if(value%i==0){
                return false;
            }
        }
       
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int mini= INT_MAX;
        int maxi = INT_MIN;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(check(nums[i])==true){
                maxi = max(maxi,i);
                mini = min(mini,i);
            }
        }
         cout<<maxi<<" "<<mini;
        return maxi-mini;
        
    }
};