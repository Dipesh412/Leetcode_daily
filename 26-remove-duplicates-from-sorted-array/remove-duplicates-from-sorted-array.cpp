class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>ans;
        if(nums.size()==1){
            return 1;
        }
        for(int i=0; i<nums.size(); i++){
            ans.insert(nums[i]);
        }
        int ii=0;
        for(int i:ans){
            nums[ii] = i;
            ii++;
        }
        return ans.size(); 
    }
};