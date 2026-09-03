class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int total = m*n;

        k%=total;

        vector<vector<int>>ans(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                int idx1 = i*n +j;
                int idx2 = (idx1+k)%total;

                int newRow = idx2/n;
                int newCol = idx2%n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};