class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& ra) {
        vector<int>inde(n,0);
        vector<int>adj[n];
        vector<int>ans;
        for(auto it: ra){
            adj[it[1]].push_back(it[0]); 
        }

        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                inde[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(inde[i]==0){
                q.push(i); 
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node); 
            for(auto it : adj[node]){
                inde[it]--;
                if(inde[it]==0){
                    q.push(it); 
                }
            }
        } 
        if(ans.size()==n) return ans;
        return {};
    }
};