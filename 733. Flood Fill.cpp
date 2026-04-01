// Time	O(m × n)
// Space	O(m × n)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), -1));
        bfs(sr,sc,color,image,vis,originalColor);
        return image;
    }

    void bfs(int i, int j, int color, vector<vector<int>>& image, vector<vector<int>>& vis, int originalColor){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = color;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int d=0; d<4; d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && image[nrow][ncol] == originalColor && vis[nrow][ncol] != color){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = color;
                }
            }
        }

        for(int i=0; i<image.size(); i++){
            for(int j=0; j<image[0].size(); j++){
                if(vis[i][j] == color) image[i][j] = color;
            }
        }
    }
};
