class Solution { 
public: 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        
        vector<vector<int>> adjLs(numCourses); 
        for(auto& edge : prerequisites){ 
            adjLs[edge[1]].push_back(edge[0]); 
        } 
        
        vector<int> indegree(numCourses, 0); 
        for(int i = 0; i < numCourses; i++) { 
            for(auto it : adjLs[i]) { 
                indegree[it]++; 
            } 
        } 
        
        queue<int> q; 
        for(int i = 0; i < numCourses; i++){ 
            if(indegree[i] == 0){ 
                q.push(i); 
            } 
        } 
        
        int cnt = 0; 
        while(!q.empty()){ 
            int node = q.front(); 
            q.pop(); 
            cnt++; 
            
            for(auto it : adjLs[node]){ 
                indegree[it]--; 
                if(indegree[it] == 0){ 
                    q.push(it); 
                } 
            } 
        } 
        
        return cnt == numCourses; 
    } 
};
