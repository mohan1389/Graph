// Time: O(n*m)
// Space: O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(tm,time);

            q.pop();

            for(int d=0; d<4; d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return time;
    }
};
