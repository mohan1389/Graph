// time: O(n * m)
// space: O(n*m)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0)), dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            dist[row][col] = steps;

            q.pop();

            for(int d = 0; d<4; d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return dist;
    }
};








//DP SOLUTION
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, n+m));

        // Step 1: Initialize
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                }
            }
        }

        // Step 2: First pass (top-left → bottom-right)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0){
                    if(i > 0)
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }

        // Step 3: Second pass (bottom-right → top-left)
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(mat[i][j] != 0){
                    if(i < n - 1)
                        dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                    if(j < m - 1)
                        dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
                }
            }
        }

        return dist;
    }
};

// 🔍 Why This Works
// First pass handles distances coming from top & left
// Second pass corrects distances using bottom & right
// Combined → captures shortest path from all 4 directions
