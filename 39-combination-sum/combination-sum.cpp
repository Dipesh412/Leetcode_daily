class Solution {
public:
    void generate(int index,vector<int> candidates,int target,vector<int>part,vector<vector<int>>&ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(part);
            }
            return;
        }
        if(candidates[index]<=target){
            part.push_back(candidates[index]);
            generate(index,candidates,target-candidates[index],part,ans);
            part.pop_back();
        }
        generate(index+1,candidates,target,part,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>part;
        generate(0,candidates,target,part,ans);
        return ans;
    }
};