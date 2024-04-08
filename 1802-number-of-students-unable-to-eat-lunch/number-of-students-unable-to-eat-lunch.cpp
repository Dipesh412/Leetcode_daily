class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stuQue;
        for(int i:students){
            stuQue.push(i);
        }
        stack<int>sandStack;
        for(int i=sandwiches.size()-1; i>=0; i--){
            sandStack.push(sandwiches[i]);
        }

        int serve=0;
        while(!stuQue.empty() && serve<stuQue.size()){
            if(stuQue.front()==sandStack.top()){
                stuQue.pop();
                sandStack.pop();
                serve=0;
            }
            else{
                stuQue.push(stuQue.front());
                stuQue.pop();
                serve++;
            }
        }
        return serve;
    }
};