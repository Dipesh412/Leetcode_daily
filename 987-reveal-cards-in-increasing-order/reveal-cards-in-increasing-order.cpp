class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n);
        deque<int>dq;
        for(int i=0; i<n; i++){
            dq.push_back(i);
        }
        sort(deck.begin(),deck.end());
        int flag=0;
        int change=0;
        while(dq.size()>0){
            if(flag==0){
                ans[dq.front()]=deck[change++];
                dq.pop_front();
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
            flag^=1;
        }
        return ans;

    }
};