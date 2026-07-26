class Solution {
public:
    void dfs(int i , vector<int> adjLS[] , vector<int> &vis){
        vis[i]=1;
        for(auto &it : adjLS[i]){
            if(vis[it]==0){
                dfs(it , adjLS , vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLS[n];
        for(int i =0 ; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                cnt++;
                dfs(i , adjLS , vis);
            }
        }
       return cnt; 
    }
};