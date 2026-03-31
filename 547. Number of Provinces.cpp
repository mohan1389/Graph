//converting adjacency matrix matrix to adj list
//TC: O(v^2)
//SC: O(V+E)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int cnt = 0;
        vector<int> vis(V,0);

        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++) { // adjecency matrix -> adjecency list
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
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
