class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&rid,int n, int m  ){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nx = r + dr[i];
            int ny = c + dc[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny] == 0 && rid[nx][ny] == 1){
                dfs(nx,ny,vis,rid,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& rid) {
        int n = rid.size();
        int m = rid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){
                    if(rid[i][j] == 1){
                        dfs(i,j,vis,rid,n,m);
                    }
                    
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};