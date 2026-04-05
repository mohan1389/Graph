// MANTRA: AGR KOI NODE ALREADY VISITED HAI AUR CURR NODE KA PARENT B NII HAI, THEN THER IS A CYCLE
//TC: O(V+2E)
//SC: O(V)
class Solution{
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if( bfs(i,adj,vis)) return true;
            }
        }
        return false;
    }

    bool bfs(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;

        queue<pair<int,int>> q;

        q.push({src,-1}); // keeping parent as -1 for start node

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent) return true;
            }
        }
        return false;
    }
};
