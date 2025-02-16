class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
      void dfs(vector<vector<char>>&board, vector<vector<int>>&vis, int r, int c){
        vis[r][c] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<4; i++){
            int nx = r + dr[i];
            int ny = c+ dc[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny] == 0 && board[nx][ny] == 'O'){
                dfs(board,vis,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0; i<m; i++ ){
            if(board[0][i]== 'O' && !vis[0][i]){
                dfs(board,vis,0,i);
            }
            if(board[n-1][i] == 'O' && !vis[n-1][i] ){
                dfs(board,vis,n-1,i);
            }
        }

        for(int i=0; i<n; i++ ){
            for(int j=0 ; j<m; j++){
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }    
        for(int i=0; i<n; i++){
            if(board[i][0]== 'O' && !vis[i][0]){
                dfs(board,vis,i,0);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1] ){
                dfs(board,vis,i,m-1);
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};