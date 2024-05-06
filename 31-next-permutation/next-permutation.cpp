class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind ,i;
        for(ind=n-2; ind>=0; ind--){
            if(nums[ind] <nums[ind+1]){
                break;
            }
        }
        if(ind<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(i=n-1; i>ind; i--){
                if(nums[i]>nums[ind]){
                    break;
                }
            }
            swap(nums[ind],nums[i]);
            reverse(nums.begin()+ind+1,nums.end());
        }
        

    }
};