class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int initialColor = image[sr][sc];
        
        
        if (initialColor == color) return;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color; 
        
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
                    
                    if (image[newrow][newcol] == initialColor) {
                        image[newrow][newcol] = color; 
                        q.push({newrow, newcol});
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image, sr, sc, color);
        return image;
    }
};
