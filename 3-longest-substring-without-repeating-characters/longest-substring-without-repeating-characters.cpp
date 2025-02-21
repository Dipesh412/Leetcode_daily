class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<int>st;
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            while(st.find(s[i]) != st.end()){
                st.erase(s[left]);
                left++;
            } 

            st.insert(s[i]);
            maxi = max(maxi, i-left+1);
        }

        return maxi;
    }
};