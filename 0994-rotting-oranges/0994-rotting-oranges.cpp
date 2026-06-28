class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; /*-----{{row, col} , time}*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    cntFresh += 1;
                }
            }
        }

        int cntRotten = 0;
        int tm = 0;

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while (!q.empty()) {
             int row = q.front().first.first;
             int col = q.front().first.second;
             int t = q.front().second;

            tm =max(tm,t);

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                // To check condition and validations---
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                    cntRotten++;
                }
            }
        }
        if(cntFresh!=cntRotten) return -1;
        return tm;
    }
};