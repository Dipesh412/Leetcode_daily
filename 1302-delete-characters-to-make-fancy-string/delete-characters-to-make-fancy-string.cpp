class Solution {
public:
    string makeFancyString(string s) {
        int cnt =1;
        string ans; 
        char value = s[0] ;
        ans += s[0];
        for(int i=1; i<s.size(); i++){

            if(value == s[i]){
                cnt ++;
                if(cnt >= 3){
                cnt--;
                continue;
            }
       
            }
            
            else{
                cnt = 1;
                value = s[i];
                
            }
            
            ans+=s[i];
        }
        return ans;
    }
};