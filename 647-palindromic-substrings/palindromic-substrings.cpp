class Solution {
public:
    int cal(string s,int l,int r){
        int cnt =0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            int odd = cal(s,i,i);
            int even = cal(s,i,i+1);
            cnt += even+odd;
        }
        return cnt;
    }
};