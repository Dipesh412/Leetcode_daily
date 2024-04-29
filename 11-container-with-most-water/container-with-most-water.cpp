class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxWater =0;
        while(l<r){
            int curWater = min(height[l],height[r]);
            maxWater = max(maxWater,curWater*(r-l));
            while(height[l]<=curWater && l<r){
                l++;
            }
            while(height[r]<=curWater && l<r){
                r--;
            }

        }
        return maxWater;

    }
};