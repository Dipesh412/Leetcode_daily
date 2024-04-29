class Solution {
public:
    bool isPalindrome(int x) {
        long long int num=0;
        int prev = x;
        if(x<0){
            return false;
        }
        else{
            while(x>0){
                int dig = x%10;
                num = (num*10)+dig;
                x=x/10;
            }

        }
        if(prev==num){
            return true;
        }
        return false;
        
    }
};