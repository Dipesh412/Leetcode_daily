class Solution {
public:
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size(); 
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>ans(n, vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++ ){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0}) ;
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }

            }
        }

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[x][y] = step;
            for(int i=0; i<4; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 && ny<m && nx<n && ny>=0 && vis[nx][ny]==0){
                    q.push({{nx,ny}, step+1});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};