class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        int buy = prices[0];
        int pr = 0;

        for(int i=1; i<prices.size(); i++){
            if(buy > prices[i]){
                buy = prices[i];
            }
            pr = max(pr, prices[i]-buy);
        }
        return pr;
    }
};