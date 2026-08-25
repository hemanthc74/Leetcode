class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        return dfs(source,destination,adj,vis);
    }

    bool dfs(int u , int dest , vector<vector<int>> &adj , vector<bool> &vis){
        if(u==dest) return true;
        vis[u] = true;
        for(auto &it: adj[u]){
            if(!vis[it]){
                if(dfs(it,dest,adj,vis)) return true;
            }
        }

        return false;
    }
};