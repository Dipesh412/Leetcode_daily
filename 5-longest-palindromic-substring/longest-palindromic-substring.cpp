class Solution {
public:
    int cal(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start=0,end=0;

        for(int i=0; i<s.size(); i++){
            int odd = cal(s,i,i);
            int even = cal(s,i,i+1);
            int maxLength = max(odd,even);
            if(maxLength>end-start){
                start = i-(maxLength-1)/2;
                end = i+maxLength/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};