class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> vis(n+2,0);
        for(auto it: edges){
            vis[it[0]]++;
            vis[it[1]]++;
        }
        for(int i=1;i<n+2;i++){
            if(vis[i]==n) return i;
        }

        return -1;
    }
};