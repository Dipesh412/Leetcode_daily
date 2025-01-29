class Solution {
public:
    long  f(int ind, string s, int sign, long result){
        if(result > INT_MAX ){
            if(sign == -1){
                return INT_MIN;
            }
            return INT_MAX;
        }
        if(ind==s.size()){
            return sign*result;
        }
        if(s[ind] < '0' || s[ind] > '9'){
            return sign*result;
        }
        return f(ind+1,s,sign,result*10+(s[ind]-'0'));
    }
    int myAtoi(string s) {
        int sign = 1;
        int i=0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
         if(s[i] == '-'){
            sign = -1;
            i++;
         } else if(s[i] == '+'){
            i++;
         }
         
        long result = f(i,s,sign, 0);
        return result;
    }
};