class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        vector<int>n1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                n1.push_back(nums[i]); 
                
            }else{
                cnt++;
            }
            
        }
        for(int i=0; i<n1.size(); i++){
            nums[i]=n1[i];
        }
        return nums.size()-cnt;
    }
};