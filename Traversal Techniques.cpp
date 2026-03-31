class Solution {  //TC: O(V+E) | SC: O(V+E) + O(v)- auxiliary stack space
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
     vector<int> vis(V,0);
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }

        return ans;
    }

    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans){
            vis[node] = 1;
            ans.push_back(node);
    
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, ans);
                }
            }
        }
    };
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) { //TC: O(V+E) | SC: O(V+E)
        vector<int> vis(V,0);
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bfs(i, adj, vis, ans);
            }
        }

        return ans;
    }

    void bfs(int start, vector<int> adj[], vector<int> &vis, vector<int> &ans){
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }

        }
    }
