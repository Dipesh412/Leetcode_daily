class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[nums[i]%1000]>=1000){
                ans.push_back(nums[i]%1000);
            }
            nums[nums[i]%1000]+=1000;
        }
        return ans;
    }
};