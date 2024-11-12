class Solution {
public:
    void bfs(int row , int col, vector<vector<int>>&visited, vector<vector<char>>& grid){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int i  = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i+1][j] == '1' && !visited[i+1][j]){
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j+1] == '1' && !visited[i][j+1]){
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }
            if(i - 1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j]){
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }
            if(j - 1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1]){
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }
            
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};