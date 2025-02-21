class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int n = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                n++;
            }
            if(n<= k){
                maxi = max(maxi , i-left+1);
            }
            if(n > k){
                if(nums[left]==0){
                    n--;
                }
                left++;
                
            }
        }
        return maxi;
    }
};