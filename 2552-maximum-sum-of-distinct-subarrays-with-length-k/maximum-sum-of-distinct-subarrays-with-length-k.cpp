class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int,int>mp;
        long long maxi = 0;

        int l=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mp[nums[i]]++;
            if(i-l+1 > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                sum -= nums[l];
                l++;
            }
            if(mp.size() == k && (i-l+1)==k){
                maxi = max(maxi,sum);
            }
        }

        return maxi;
        
        


    }
};