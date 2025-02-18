class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        set<vector<int>>st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int k = j+1, l = n-1;
                while(k<l){
                    if((long long) nums[i] + (long long)nums[j] + (long long) nums[k] +(long long) nums[l] == tar){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }else if((long long)nums[i] +(long long) nums[j] + (long long)nums[k] +(long long) nums[l] > tar){
                        l--;
                    }else{
                        k++;
                    }
                } 
            }
        }

        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};