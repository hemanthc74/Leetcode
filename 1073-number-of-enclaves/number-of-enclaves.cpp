class Solution {
public:
    void dfs (int row , int col , vector<vector<int>> &grid , vector<vector<int>> & vis){
        int n = grid.size();
        int m = grid[0].size();

        if(grid[row][col]==0){
            return;
        }

        int duprow[] = {-1,1,0,0};
        int dupcol[] = {0,0,1,-1};
        for(int i=0 ;i<4 ;i++){
            int newrow = row+ duprow[i];
            int newcol = col + dupcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && vis[newrow][newcol]==0){
                vis[newrow][newcol] =1;
                dfs(newrow , newcol , grid , vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1 && grid[i][j]==1){
                    vis[i][j]=1;
                    dfs(i,j,grid,vis);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};