class Solution {
public:
    bool dfs(int node, int col, vector<int>&color, vector<vector<int>>&ra){
        color[node] = col;
        for(auto it : ra[node] ){
            if(color[it]==-1){
                if(dfs(it,!col,color,ra)==false){
                    return false;
                }
            }else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& ra) {
        int V = ra.size();
        
       vector<int>color(V,-1);
        for(int i=0; i<V; i++ ){
            if(color[i] == -1){
                if(dfs(i,0,color,ra)== false){
                    return false;
                }
            }
        }
        return true;
    }
};