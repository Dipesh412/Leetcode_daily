class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       vector<int>start,end;
       for(const auto &interval: intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);

       } 
       sort(start.begin(), start.end());
       sort(end.begin(), end.end());

       int e = 0, g_cnt = 0;
       for(int s:start){
        if(s>end[e]){
            e++;
        }
        else{
            g_cnt++;
        }
       }
       return g_cnt;
    }
};