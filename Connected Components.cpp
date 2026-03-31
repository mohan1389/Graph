class Solution {
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> vis(V,0);
        // vis[0] = 1;
        int cnt = 0;

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        for(int i=0; i<V; i++){
            if(!vis[i]){
                bfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }


    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
};
