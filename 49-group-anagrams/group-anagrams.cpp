class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(int i=0; i<strs.size(); i++){
            string s= strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>>ans(m.size());
        int id =0;
        for(auto x:m){
            auto v = x.second;
            for(int i=0; i<v.size(); i++){
                ans[id].push_back(v[i]);
            }
            id++;
        }
        return ans;
    }
};