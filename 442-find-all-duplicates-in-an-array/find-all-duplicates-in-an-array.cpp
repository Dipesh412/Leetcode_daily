class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto mp:m){
            if(mp.second>1){
                v.push_back(mp.first);
            }
        }
        return v;
    }
};