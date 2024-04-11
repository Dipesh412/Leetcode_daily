class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>st;
        string result;
        for(char c:num){
            while(k>0 && !st.empty() && st.back()>c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        for(char c:st){
            if(result.empty() && c=='0') continue;
            result.push_back(c);
        }
        return result.empty()?"0":result;
    }
};