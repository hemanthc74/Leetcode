class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        q.push({row, col});
        vis[row][col] = 1;
        
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int newrow = r + delRow[i];
                int newcol = c + delCol[i];
                
                
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                    
                    if (grid[newrow][newcol] == '1' && !vis[newrow][newcol]) {
                        vis[newrow][newcol] = 1;
                        q.push({newrow, newcol}); 
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }   
};
