class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Fast I/O for competitive programming / LeetCode speedups
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = graph.size();
        vector<vector<int>> adjrev(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> isSafe(n, false);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            isSafe[node] = true; 

            for(auto it : adjrev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        vector<int> safenodes;
        for(int i = 0; i < n; i++) {
            if(isSafe[i]) {
                safenodes.push_back(i);
            }
        }

        return safenodes;
    }
};
