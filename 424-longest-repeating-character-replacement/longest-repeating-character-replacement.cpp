class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxifeq = 0, maxi=0;
        unordered_map<char,int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            maxifeq = max(maxifeq,mp[s[i]]);
            while((i-l+1)-maxifeq>k){
                mp[s[l]]--;
                l++;
            } 
            maxi = max(maxi,(i-l+1));
        }
        return maxi;
    }
};