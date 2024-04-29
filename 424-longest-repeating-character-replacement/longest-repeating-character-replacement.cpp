class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,maxFre=0,maxLength = 0;
        int hash[26]={0};
        while(right<s.size()){
            hash[s[right]-'A']++;
            maxFre = max(maxFre,hash[s[right]-'A']);
            while((right-left+1)-maxFre>k){
                hash[s[left]-'A']--;
                maxFre =0;
                for(int i=0; i<25; i++){
                    maxFre = max(maxFre,hash[i]);
                }
                left++;
            }
            if((right-left+1)-maxFre<=k){
                maxLength = max(maxLength,(right-left+1));
            }
            right++;
        }
        return maxLength;
    }
};