class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str="";
        
        int open=0;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                if(open==0){
                    s[i]='*';
                }
                else{
                    open--;
                }
            }
        }

        for(int i=s.size()-1; i>=0; i--){
            if(open>0 && s[i]=='('){
                s[i]='*';
                open--;
            }
        }
        string ans ="";
        for(int i=0; i<s.size(); i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};