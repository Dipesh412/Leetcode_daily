class Solution {
public:
    bool dfs(vector<int>&vis, int node, vector<int> adj[], stack<int>&st, vector<int>&patVis){
        vis[node] = 1;
        patVis[node] =1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(vis,it,adj,st,patVis)== true){
                    return true;
                }
            }else if(patVis[it] ){
                return true;
            }
            
        }
        st.push(node); 
        patVis[node] =0;
        return false;
    }
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<int>vis(v,0);
        vector<int>patVis(v,0);
        vector<int>adj[v];
        for ( auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        stack<int>st;
        int l = 0;
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(dfs(vis,i,adj,st,patVis)== true){
                    return {};
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop(); 
        } 
        return ans;
    }
};