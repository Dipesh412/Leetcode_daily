class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int cnt=0,maxi=INT_MIN;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                cnt++;
                st.push(s[i]);
                maxi = max(maxi,cnt);
            }
            if(s[i]==')'){
                cnt--;
                st.pop();
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};