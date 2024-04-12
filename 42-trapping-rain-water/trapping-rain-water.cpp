class Solution {
public:
    int trap(vector<int>& height) {
        int i=0 , maxLeft=height[0],sum=0;
        int j=height.size()-1,maxRight = height[j];
        while(i<j){
            if(maxLeft<=maxRight){
                sum+=(maxLeft-height[i]);
                i++;
                maxLeft = max(maxLeft,height[i]);
            }else{
                sum+=(maxRight-height[j]);
                j--;
                maxRight = max(maxRight,height[j]);
            }
        }
        return sum;
    }
};