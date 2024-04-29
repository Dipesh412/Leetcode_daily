class Solution {
public:
    string minWindow(string s, string t) {
        int startInd=-1,l=0,r=0,minLength = INT_MAX,cnt=0;
        unordered_map<char,int>mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }
        while(r<s.size()){
            if(mp[s[r]]>0) {
                cnt++;
            }
            mp[s[r]]--;
            while(l<=r && cnt==t.size()){
                
                if((r-l+1)<minLength){
                    minLength = r-l+1;
                    startInd =l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt=cnt-1;
                l++;
            }
            r++;
        }
        return minLength==INT_MAX?"":s.substr(startInd,minLength);
    }
};