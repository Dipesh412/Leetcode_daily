class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>st;
        for(int i=0; i<nums.size(); i++){
            int n = target-nums[i];
            if(st.find(n)==st.end()){
                st[nums[i]]=i;
            }
            else{
                return {st[n],i};
            }
        }
        return {0};
    }
};