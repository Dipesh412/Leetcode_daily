class Solution {
public:
    void generate(int open,int close,vector<string>&ans,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open>0){
            generate(open-1,close,ans,op+'(');
        }
        if(open<close){
            generate(open,close-1,ans,op+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string op="";
        int open=n;
        int close = n;
        generate(open,close,ans,op);
        return ans;
    }
};