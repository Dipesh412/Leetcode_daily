class Solution {
public:
    void generate(int index,vector<string>&ans,string output,string digits,string mapping []){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index]-'0';
        string value = mapping[number];
        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            generate(index+1,ans,output,digits,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        if(digits.size()==0){
            return ans;
        }
        generate(index,ans,output,digits,mapping);
        return ans;
    }
};