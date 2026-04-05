//DFS SOLUTION | basically this problem is cycle detection in directed graph
//WE USE path_vis CONCEPT THIS WILL WORK ONLY IF WE USE DFS, BCOZ DFS GOES DEEP ON A PATH, BUT BFS EXPLORES LEVEL WISE. IF YOU WANT TO USE BFS GO FOR indegree[] method
// Time	O(V + E)
// Space	O(V + E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> vis(V,0);
        vector<int> path_vis(V,0);

        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites){
            int u = it[1]; // prerequisite
            int v = it[0]; // course

            adj[u].push_back(v);
        }
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis,path_vis,adj)) return false;
            }
        }
        return true;
    }


    bool dfs(int src, vector<int> &vis, vector<int> &path_vis, vector<vector<int>> &adj){
        vis[src] = 1;
        path_vis[src] = 1;

        for(auto it : adj[src]){
            if(!vis[it]){
                if(dfs(it, vis,path_vis,adj)) return true;
            }
            else if(path_vis[it]) return true;
        }
        path_vis[src] = 0;
        return false;
    }
};



//BFS SOLUTION
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Step 1: Build graph
        for(auto &it : prerequisites){
            int u = it[1]; // prerequisite
            int v = it[0]; // course

            adj[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: Push all indegree 0 nodes
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        // Step 3: BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        // Step 4: Check cycle
        return count == numCourses;
    }
};
