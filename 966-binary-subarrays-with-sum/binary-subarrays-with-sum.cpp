class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int oal) {
        int sum = 0;
        unordered_map<int,int>mp;
        int cnt = 0;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum - oal) != mp.end() ){
                cnt += mp[sum-oal];
            }
            mp[sum]++;
        }
        return cnt;
    }
};